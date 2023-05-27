#pragma once
#include "Fase.h"
#include "SingleFrameAnimation.h"

namespace Fases {
    class Fase1 :
        public Fases::Fase
    {
    private:
        SingleFrameAnimation Background;
    public:
        Fase1(Entidades::Personagens::Jogador* j1);
        ~Fase1();
        void inicializaElementos();
    };
}
