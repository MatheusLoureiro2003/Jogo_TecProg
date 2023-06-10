#pragma once
#include "Fase.h"

namespace Fases {
    class Cyberpunk :
        public Fases::Fase
    {
    public:
        Cyberpunk();
        ~Cyberpunk();
        void createBackground();
        void createMap();
    };
}
