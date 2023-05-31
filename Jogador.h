#pragma once
#include "Personagem.h"

#define VELOCIDADE_JOGADOR 200.0f
namespace Gerenciadores { class Gerenciador_Evento; }
namespace Gerenciadores { class Gerenciador_Colisoes; }

namespace Entidades {
    namespace Personagens {
        class Jogador :
            public Entidades::Personagens::Personagem
        {
        private:
        public:
            Jogador();
            ~Jogador();
            //void move();
            void atualizar();
            //int getVidas() { return num_Vidas; }
            //void executar();
        };
    }
}

