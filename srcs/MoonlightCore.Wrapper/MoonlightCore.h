#pragma once
#include "ManagedObject.h"
#include "../MoonlightCore/MoonlightCore.h"

using namespace System;

namespace Moonlight
{
	namespace Wrapper
	{
		public ref class MoonlightCore : public ManagedObject<Moonlight::MoonlightCore>
		{
		public:
			MoonlightCore();
		};
	}
}