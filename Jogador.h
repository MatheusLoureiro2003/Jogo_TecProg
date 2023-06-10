#pragma once
#include "Personagem.h"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.3f
#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f

namespace Observadores {
    class ObserverPlayer;
}

namespace Entidades {
    namespace Personagens {
        class Jogador :
            public Entidades::Personagens::Personagem
        {
         private:
            void inicializa();
            bool first;
            bool onFloor;
            Observadores::ObserverPlayer* observerPlayer;
        public:
            Jogador(const sf::Vector2f pos, bool first);
            ~Jogador();
            //void move();
            void atualizar();
            void setFirst(const bool first);
            bool getFirst();
            void jump();
            void canJump();
            void changeObserverState();

            //int getVidas() { return num_Vidas; }
            //void executar();
        };
    }
}

