#pragma once
#include "Personagem.h"

namespace Entidades {
    namespace Personagens {
        class Jogador :
            public Entidades::Personagens::Personagem
        {
        private:
        public:
            Jogador();
            ~Jogador();
            void move();
            //int getVidas() { return num_Vidas; }
            //void executar();
        };
    }
}

