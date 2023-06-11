#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Entidade.h"
#include "Ente.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include "MainMenu.h"



class Jogo
{
private:
	static Gerenciadores::Gerenciador_Eventos* pEve;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	Menus::MainMenu mainMenu;

public:
	Jogo();
	~Jogo();
	void Executar();

};

