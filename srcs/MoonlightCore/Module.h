#pragma once
#include <Windows.h>

namespace MoonlightCore
{
	class Module
	{
	public:
		static Module CreateModule();
		Module(unsigned int moduleBase, unsigned int moduleSize);
		template<typename T>
		T FindPattern(const char* signature, const char* mask)
		{
			return (T)Find(signature, mask);
		}
	private:
		unsigned int _moduleBase;
		unsigned int _moduleSize;
		byte* Find(const char* signature, const char* mask) const;
		bool Match(const byte* data, const char* signature, const char* mask) const;
	};
}

