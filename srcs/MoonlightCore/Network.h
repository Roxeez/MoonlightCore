#pragma once
#include "Module.h"

namespace Moonlight
{
	class Network
	{
	private:
		Module _module;

		unsigned int _recvPacketAddress;
		unsigned int _sendPacketAddress;
		unsigned int _callerObject;

	public:
		Network(Module module);

		void SendPacket(const char* packet);
		void ReceivePacket(const char* packet);

		static void OnPacketReceived();
		static void OnPacketSend();
	};
}