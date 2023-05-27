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
            void atualizar();
            //int getVidas() { return num_Vidas; }
           // void executar();
        };
    }
}

