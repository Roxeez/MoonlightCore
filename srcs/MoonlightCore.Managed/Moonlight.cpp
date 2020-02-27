#include "Moonlight.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MoonlightCore
{
	namespace Managed
	{

		ManagedMoonlight::ManagedMoonlight()
		{
			Module module = Module::CreateModule();

			_network = MoonlightCore::Network::GetInstance()->Setup(module);
			_character = new Character(module);

			IntPtr recvPointer = Marshal::GetFunctionPointerForDelegate(PacketReceived);
			IntPtr sendPointer = Marshal::GetFunctionPointerForDelegate(PacketSend);

			_network->SetCallback(PacketType::RECV, static_cast<PacketCallback>(recvPointer.ToPointer()));
			_network->SetCallback(PacketType::SEND, static_cast<PacketCallback>(sendPointer.ToPointer()));
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