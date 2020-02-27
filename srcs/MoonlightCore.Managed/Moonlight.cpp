#include "Moonlight.h"

using namespace System;

namespace MoonlightCore
{
	namespace Managed
	{
		ManagedMoonlight::ManagedMoonlight()
		{
			Module module = Module::CreateModule();

			_network = MoonlightCore::Network::GetInstance()->Setup(module);
			_character = new Character(module);
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
			_character->Walk(x, y);
		}
	}
}