#pragma once
#include "Jogador.h"
#include "Inimigo.h"

namespace Construtor {
	class Construtor_Entidades
	{
    private:
        Entidades::Personagens::Jogador* pjogador1;
        void verificaJogador();
    public:
        Construtor_Entidades(Entidades::Personagens::Jogador* pjogador1);
        Construtor_Entidades();
        ~Construtor_Entidades();
        Entidades::Entidade* createEnemy(const sf::Vector2f pos, const sf::Vector2f tam);
        Entidades::Entidade* createPlayer(const sf::Vector2f pos, bool first);
	};
}
