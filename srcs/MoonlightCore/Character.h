#pragma once
#include "Module.h"

namespace MoonlightCore
{
	class Character
	{
	public:
		Character(Module module);
		void Walk(short x, short y);
	};
}

