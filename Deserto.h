#pragma once
#include "Fase.h"

namespace Fases {
    class Deserto :
        public Fase
    {
    public:
        Deserto();
        ~Deserto();
        void createBackground();
        void createMap();
    };
}