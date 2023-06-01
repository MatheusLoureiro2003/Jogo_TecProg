#pragma once
#include "Personagem.h"

#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f

#define VELOCIDADE_JOGADOR 200.0f
namespace Gerenciadores { class Gerenciador_Evento; }

namespace Entidades {
    namespace Personagens {
        class Jogador :
            public Entidades::Personagens::Personagem
        {
         private:
            void inicializa();

        public:
            Jogador(const sf::Vector2f pos);
            ~Jogador();
            //void move();
            void atualizar();
           

            //int getVidas() { return num_Vidas; }
            //void executar();
        };
    }
}

