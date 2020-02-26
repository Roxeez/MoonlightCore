#include "Moonlight.h"

namespace MoonlightCore
{
	Moonlight::Moonlight()
	{
		_module = &Module::CreateModule();
		_network = Network::GetInstance();
	}

	Network* Moonlight::GetNetwork()
	{
		return _network;
	}
}