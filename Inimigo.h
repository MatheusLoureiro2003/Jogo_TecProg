#pragma once
#include "Personagem.h"

#define VELOCIDADE_INIMIGO 50.0f

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

