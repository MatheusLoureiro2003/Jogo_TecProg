#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"

class Ente
{
protected:
	int id;
	static Gerenciador_Grafico* pGG;
	sf::RectangleShape body;

public:
	Ente();
	~Ente();
	//virtual void executar() = 0;
	void setGerenciadorGrafico(Gerenciador_Grafico* pGG) { this->pGG = pGG; }
	//void setWindow(sf::RenderWindow* window) { pWindow = window;}
	virtual void draw() = 0;
	
};

