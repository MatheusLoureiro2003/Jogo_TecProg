#pragma once
#include "Fase.h"
#include "UmaAnimacaoFrame.h"

namespace Fases {
    class Fase1 :
        public Fases::Fase
    {
    private:
        UmaAnimacaoFrame Background;
    public:
        Fase1(Entidades::Personagens::Jogador* j1);
        ~Fase1();
        void inicializaElementos();
    };
}
