#pragma once
#include "Network.h"
#include "Module.h"

namespace Moonlight
{
	class MoonlightCore
	{
	private:
		Module _module;
		Network _network;
	public:
		MoonlightCore();

		Network GetNetwork() const;
		Module GetModule() const;
	};
}