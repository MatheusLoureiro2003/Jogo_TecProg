#pragma once
#include "Personagem.h"
#include "Jogador.h"
// usado p/ gerar números aleatórios
#include <time.h>

// utuliza a função fabs
#include <cmath>

#define VELOCIDADE_INIMIGO 50.0f
#define VELOCIDADE_INIMIGO_X 0.025f
#define VELOCIDADE_INIMIGO_Y 0.025f
#define TAMANHO_INIMIGO_X 50.0f
#define TAMANHO_INIMIGO_Y 90.0f
#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Gerenciadores { class Gerenciador_Evento; }

namespace Entidades {
    namespace Personagens {
        class Inimigo :
            public Entidades::Personagens::Personagem
        {
        private:
            Entidades::Personagens::Jogador* jogador;
            sf::Clock Relogio;
            short RamdomMoviment;
            float dtAux;
            void Inicializa();
            void MoveInimigo();
        public:
            Inimigo(const sf::Vector2f pos, Entidades::Personagens::Jogador*jogador);
            ~Inimigo();
            void atualizar();
            void ChasePlayer(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void UpdateRamdomMoviment();
        };
    }
}

