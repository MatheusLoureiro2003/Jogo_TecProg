#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include "Gerenciador_Colisao.h"
// usado p/ gerar n�meros aleat�rios
#include <time.h>

// utuliza a fun��o fabs
#include <cmath>

#define VELOCIDADE_INIMIGO 50.0f
#define VELOCIDADE_INIMIGO_X 0.025f
#define VELOCIDADE_INIMIGO_Y 0.025f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Gerenciadores { class Gerenciador_Evento; }
namespace Gerenciadores { class Gerenciador_Colisao; }

namespace Entidades {
    namespace Personagens {
        class Inimigo :
            public Entidades::Personagens::Personagem
            //public Gerenciadores::Gerenciador_Colisao
        {
        private:
            Entidades::Personagens::Jogador* jogador;
            //Gerenciadores::Gerenciador_Colisao;
            sf::Clock Relogio;
            short RamdomMoviment;
            float dtAux;
            void Inicializa();
            void MoveInimigo();
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Entidades::Personagens::Jogador*jogador);
            ~Inimigo();
            void atualizar();
            void ChasePlayer(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void UpdateRamdomMoviment();
        };
    }
}

