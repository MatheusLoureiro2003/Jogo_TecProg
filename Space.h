#pragma once
#include "Fase.h"

namespace Fases {
    class Space :
        public Fase
    {
    public:
        Space();
        ~Space();
        void createBackground();
        void createMap();
    };
}