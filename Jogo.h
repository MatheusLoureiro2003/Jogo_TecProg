#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Entidade.h"
#include "Ente.h"
#include "ListaEntidades.h"
#include "Fase.h"
#include "Gerenciador_Eventos.h"



class Jogo
{
private:
	static Gerenciadores::Gerenciador_Eventos* pEve;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	
	
	sf::Clock clock;
	float dt;
	
	
	Listas::ListaEntidades* LEs;
	Fases::Fase* fase1;
public:
	Jogo();
	~Jogo();

	void Executar();

};

