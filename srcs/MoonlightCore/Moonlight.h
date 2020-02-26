#pragma once
#include "Module.h"
#include "Network.h"

namespace MoonlightCore
{
    class Moonlight
    {
    private:
        Module* _module;
        Network* _network;
    public:
        Moonlight();
        ~Moonlight()
        {
            if (_module != nullptr)
            {
                delete _module;
            }

            if (_network != nullptr)
            {
                delete _network;
            }
        }

        Network* GetNetwork();
    };
}

