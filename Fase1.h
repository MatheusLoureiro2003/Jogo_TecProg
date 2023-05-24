#pragma once
#include "Fase.h"

namespace Fases {
    class Fase1 :
        public Fases::Fase
    {
    private:

    public:
        Fase1(Entidades::Personagens::Jogador* j1);
        ~Fase1();
        void inicializaElementos();
    };
}
