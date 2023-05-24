#pragma once
#include "Personagem.h"

namespace Entidades {
    namespace Personagens {
        class Inimigo :
            public Entidades::Personagens::Personagem
        {
        private:

        public:
            Inimigo();
            ~Inimigo();
            //int getVidas() { return num_Vidas; }
           // void executar();
        };
    }
}

