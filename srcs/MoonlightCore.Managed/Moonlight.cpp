#include "Moonlight.h"

using namespace System;

namespace MoonlightCore
{
	namespace Managed
	{
		ManagedMoonlight::ManagedMoonlight()
		{
			MoonlightCore::Network* network = MoonlightCore::Network::GetInstance();
			Module module = Module::CreateModule();
			network->Setup(&module);
		}

		void ManagedMoonlight::SendPacket(System::String^ packet)
		{
			_network->SendPacket(StringToCharArray(packet));
		}

		void ManagedMoonlight::ReceivePacket(System::String^ packet)
		{
			_network->ReceivePacket(StringToCharArray(packet));
		}

		void ManagedMoonlight::Walk(short x, short y)
		{
			// TODO :
		}
	}
}