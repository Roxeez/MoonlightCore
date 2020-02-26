#pragma once
#include "ManagedObject.h"
#include "../MoonlightCore/MoonlightCore.h"

using namespace System;

namespace Moonlight
{
	namespace Wrapper
	{
		public ref class Network : public ManagedObject<Moonlight::Network>
		{
		public:
			Network();
		};
	}
}