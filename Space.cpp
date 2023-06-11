#include "Space.h"

#include "Space.h"

Fases::Space::Space() :
	Fase(IDs::fase_Space, IDs::fundo_Space)
{
}

Fases::Space::~Space()
{
}

void Fases::Space::createBackground()
{
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/Espaco/background_1.png", 0.0f);
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/Espaco/background_2.png", 0.1f);
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/Espaco/background_3.png", 0.3f);
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/Espaco/background_4.png", 0.5f);
}

void Fases::Space::createMap()
{
	listaPersonagens.addEntidade(construtorEntidade.createPlayer(sf::Vector2f(100.0f, 400.0f)));
	//listaPersonagens.addEntidade(construtorEntidade.createPlayer(sf::Vector2f(100.0f, 400.0f)));

	for (int i = 0; i < 4; i++) {
		listaPersonagens.addEntidade(construtorEntidade.createEnemy(sf::Vector2f(500.0f * (i + 1), 0.0f)));
	}
}
