#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Entidade.h"
#include "Ente.h"
#include "ListaEntidades.h"
#include "Fase1.h"
#include "Jogador.h"


class Jogo
{
private:
	
	static Gerenciadores::Gerenciador_Grafico* pGG;
	sf::Clock clock;
	float dt;
	sf::RenderWindow window;
	Entidades::Personagens::Jogador *jogador1;
	
	Listas::ListaEntidades* LEs;
	Fases::Fase1* fase1;
public:
	Jogo();
	~Jogo();

	void Executar();

};

