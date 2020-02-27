#include "Character.h"

namespace MoonlightCore
{
    DWORD _walkObject;
    DWORD _walkFunction;

	Character::Character(Module module)
	{
        _walkObject = *(DWORD*)(module.FindPattern<DWORD>("\x33\xC9\x8B\x55\xFC\xA1\x00\x00\x00\x00\xE8\x00\x00\x00\x00", "xxxxxx????x????") + 0x6);
        _walkFunction = module.FindPattern<DWORD>("\x55\x8B\xEC\x83\xC4\xEC\x53\x56\x57\x66\x89\x4D\xFA", "xxxxxxxxxxxxx");


        if (!_walkObject)
        {
            throw "Can't found walk object";
        }

        if (!_walkFunction)
        {
            throw "Can't found walk function";
        }
	}

    void Character::Walk(short x, short y)
    {
        DWORD position = (y << 16) | x;

        __asm
        {
            push 1
            xor ecx, ecx
            mov edx, position
            mov eax, dword ptr ds : [_walkObject]
            mov eax, dword ptr ds : [eax]
            call _walkFunction
        }
    }
}