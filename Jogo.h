#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Entidade.h"
#include "Personagem.h"
#include "ListaEntidades.h"
#include "Fase.h"
#include "Jogador.h"


class Jogo
{
private:
	

	sf::Clock clock;
	float dt;

	sf::RenderWindow window;
	Jogador *jogador1;
	ListaEntidades* LEs;
	Fase* fase1;
public:
	Jogo();
	~Jogo();

	void Executar();

};

