
#include "Deserto.h"

Fases::Deserto::Deserto() :
	Fase(IDs::fase_Deserto, IDs::fundo_Deserto)
{
}

Fases::Deserto::~Deserto()
{
}

void Fases::Deserto::createBackground()
{
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/desert/IndividualsLayers/DesertLayer0.png", 0.0f);
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/desert/IndividualsLayers/DesertLayer1.png", 0.1f);
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/desert/IndividualsLayers/DesertLayer2.png", 0.3f);
	background.addLayer("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Background/desert/IndividualsLayers/DesertLayer3.png", 0.5f);
}

void Fases::Deserto::createMap()
{
	listaPersonagens.addEntidade(construtorEntidade.createPlayer(sf::Vector2f(100.0f, 400.0f)));
	//listaPersonagens.addEntidade(construtorEntidade.createPlayer(sf::Vector2f(100.0f, 400.0f)));

	for (int i = 0; i < 2; i++) {
		listaPersonagens.addEntidade(construtorEntidade.createEnemy(sf::Vector2f(500.0f * (i + 1), 0.0f)));
	}
}

