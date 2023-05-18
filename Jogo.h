#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Personagem.h"
#include "ListaEntidades.h"
#include "Fase.h"
#include "Gerenciador_Grafico.h"

class Jogo
{
private:
	Gerenciadores::Gerenciador_Grafico* pGGrafico;
	Gerenciadores::Evento* pEventManager;

	sf::Clock clock;
	float dt;

	sf::RenderWindow window;
	Entidades::Jogador *jogador1;
	ListaEntidades* LEs;
	Fase* fase1;
public:
	Jogo();
	~Jogo();

	void Executar();

};

