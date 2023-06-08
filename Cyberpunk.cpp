#include "Cyberpunk.h"

namespace Fases {
	Cyberpunk::Cyberpunk() :
		Fase(IDs::fase_Cyberpunk, IDs::fundo_Cyberpunk)
	{
	}

	Cyberpunk::~Cyberpunk()
	{
	}

	void Cyberpunk::createBackground()
	{
		background.addLayer("./Assets/Background/Night/1.png", 0.0f);
		background.addLayer("./Assets/Background/Night/2.png", 0.1f);
		background.addLayer("./Assets/Background/Night/3.png", 0.3f);
		background.addLayer("./Assets/Background/Night/4.png", 0.5f);
		background.addLayer("./Assets/Background/Night/5.png", 1.0f);
	}

	void Cyberpunk::createMap()
	{
		listaPersonagens.addEntidade(construtorEntidade.createPlayer(sf::Vector2f(100.0f, 400.0f), false));
		listaPersonagens.addEntidade(construtorEntidade.createPlayer(sf::Vector2f(100.0f, 400.0f), true));

		for (int i = 0; i < 2; i++) {
			listaPersonagens.addEntidade(construtorEntidade.createEnemy(sf::Vector2f(500.0f * (i + 1), 0.0f), sf::Vector2f(100.0f, 400.0f)));
		}
	}
}