#include "Module.h"
#include <Psapi.h>

namespace MoonlightCore
{
	Module Module::CreateModule()
	{
		HMODULE moduleHandle = GetModuleHandleA(nullptr);
		if (!moduleHandle)
		{
			throw "Can't find module handle";
		}

		MODULEINFO moduleInfo = {};
		if (!GetModuleInformation(GetCurrentProcess(), moduleHandle, &moduleInfo, sizeof(moduleInfo)))
		{
			throw "Can't get module handle information";
		}

		unsigned int moduleBase = reinterpret_cast<unsigned int>(moduleInfo.lpBaseOfDll);
		unsigned int moduleSize = moduleInfo.SizeOfImage;

		return Module(moduleBase, moduleSize);
	}

	Module::Module(unsigned int moduleBase, unsigned int moduleSize) : _moduleBase(moduleBase), _moduleSize(moduleSize)
	{

	}

	byte* Module::Find(const char* signature, const char* mask) const
	{
		for (int i = 0; i < _moduleSize; i++)
		{
			byte* data = &reinterpret_cast<byte*>(_moduleBase)[i];
			if (Module::Match(data, signature, mask))
			{
				return data;
			}
		}
	}

	bool Module::Match(const byte* data, const char* signature, const char* mask) const
	{
		for (int i = 0; i < strlen(mask); i++)
		{
			if (mask[i] == 'x' && data[i] != static_cast<byte>(signature[i]))
			{
				return false;
			}
		}
		return true;
	}
}