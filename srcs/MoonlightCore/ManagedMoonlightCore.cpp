#include "ManagedMoonlightCore.h"
#include "NtString.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MoonlightCore
{
	ManagedMoonlightCore::ManagedMoonlightCore()
	{
		Module module = Module::CreateModule();

		_network = MoonlightCore::Network::GetInstance()->Setup(module);
		_character = new Character(module);
	}

	void ManagedMoonlightCore::SendPacket(System::String^ packet)
	{
		_network->SendPacket(NtString(StringToCharArray(packet)).ToString());
	}

	void ManagedMoonlightCore::ReceivePacket(System::String^ packet)
	{
		_network->ReceivePacket(NtString(StringToCharArray(packet)).ToString());
	}

	void ManagedMoonlightCore::Walk(short x, short y)
	{
		_character->Walk(x, y);
	}

	void ManagedMoonlightCore::SetRecvCallback(NetworkCallback^ callback)
	{
		IntPtr functionPointer = Marshal::GetFunctionPointerForDelegate(callback);
		_network->SetCallback(PacketType::RECV, static_cast<PacketCallback>(functionPointer.ToPointer()));
	}

	void ManagedMoonlightCore::SetSendCallback(NetworkCallback^ callback)
	{
		IntPtr functionPointer = Marshal::GetFunctionPointerForDelegate(callback);
		_network->SetCallback(PacketType::SEND, static_cast<PacketCallback>(functionPointer.ToPointer()));
	}
}