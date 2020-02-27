#pragma once
#include "Module.h"

namespace MoonlightCore
{
	class Character
	{
	private:
		DWORD _walkObject;
		DWORD _walkFunction;
	public:
		Character(Module module);
		void Walk(short x, short y);
	};
}

