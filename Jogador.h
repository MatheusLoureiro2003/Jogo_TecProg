#pragma once
#include "Personagem.h"

namespace Entidades {
    class Jogador :
        public Personagem
    {
    private:
    public:
        Jogador();
        ~Jogador();
        void move();
    };
}

