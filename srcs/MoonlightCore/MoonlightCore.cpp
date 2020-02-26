#include "MoonlightCore.h"

namespace Moonlight
{
	MoonlightCore::MoonlightCore() : _module(Module::CreateModule()), _network(_module)
	{
		
	}

	Network MoonlightCore::GetNetwork() const
	{
		return _network;
	}

	Module MoonlightCore::GetModule() const
	{
		return _module;
	}
}