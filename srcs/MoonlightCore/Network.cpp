#include "Network.h"
#include <detours.h>

namespace Moonlight
{
	Network::Network(Module module) : _module(module)
	{
        _recvPacketAddress = module.FindPattern<unsigned int>("\x55\x8B\xEC\x83\xC4\xF4\x53\x56\x57\x33\xC9\x89\x4D\xF4\x89\x55\xFC\x8B\xD8\x8B\x45\xFC\xE8\x00\x00\x00\x00\x33\xC0", "xxxxxxxxxxxxxxxxxxxxxxx????xx");
        _sendPacketAddress = module.FindPattern<unsigned int>("\x53\x56\x8B\xF2\x8B\xD8\xEB\x04", "xxxxxxxx");
        _callerObject = module.FindPattern<unsigned int>("\xA1\x00\x00\x00\x00\x8B\x00\xBA\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xE9\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x8B\x00\x8B\x40\x40", "x????xxx????x????x????x????xxxxx");

        if (!_recvPacketAddress)
        {
            throw "Can't found recv packet function";
        }

        if (!_sendPacketAddress)
        {
            throw "Can't found recv packet function";
        }

        if (_callerObject)
        {
            _callerObject = *reinterpret_cast<unsigned int*>(_callerObject + 1);
        }

        if (!_callerObject)
        {
            throw "Caller object not found";
        }

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&reinterpret_cast<void*&>(_recvPacketAddress), OnPacketReceived);
        DetourAttach(&reinterpret_cast<void*&>(_sendPacketAddress), OnPacketSend);
        DetourTransactionCommit();
	}

	void Network::SendPacket(const char* packet)
	{
        __asm
        {
            mov esi, this
            mov eax, [esi]._callerObject
            mov eax, dword ptr ds : [eax]
            mov eax, dword ptr ds : [eax]
            mov edx, packet
            call[esi]._sendPacketAddress
        }
	}

	void Network::ReceivePacket(const char* packet)
	{
        __asm
        {
            mov esi, this
            mov eax, [esi]._callerObject
            mov eax, dword ptr ds : [eax]
            mov eax, dword ptr ds : [eax]
            mov eax, dword ptr ds : [eax + 34h]
            mov edx, packet
            call[esi]._recvPacketAddress
        }
	}
}