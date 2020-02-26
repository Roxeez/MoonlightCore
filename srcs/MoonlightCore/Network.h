#pragma once
#include "Module.h"
#include "PacketType.h"
#include <map>

namespace MoonlightCore
{
	class Network
	{
		typedef bool(__stdcall* PacketCallback)(const char* packet);

		Network(Network const&) = delete;
		Network(Network&&) = delete;
		Network operator=(Network const&) = delete;
		Network operator=(Network&&) = delete;
	private:
		unsigned int _recvPacketAddress;
		unsigned int _sendPacketAddress;
		unsigned int _callerObject;

		std::map<PacketType, PacketCallback> _callbacks;

		void Setup(Module module);

		static void OnPacketReceived();
		static void OnPacketSend();
	
		bool ExecuteCallback(PacketType packetType, const char* packet);

	public:
		void SendPacket(const char* packet);
		void ReceivePacket(const char* packet);

		void SetCallback(PacketType packetType, PacketCallback callback);

		static Network* GetInstance()
		{
			static Network instance;
			return reinterpret_cast<Network*>(&instance);
		}
	protected:
		Network() = default;
	};
}