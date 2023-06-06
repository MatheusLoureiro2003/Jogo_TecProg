#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "IDs.h"

class Ente
{
protected:
	int id;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	sf::RectangleShape body;
	const IDs ID;
public:
	Ente(const IDs ID);
	~Ente();
	//virtual void executar() = 0;
	void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico* pGG) { this->pGG = pGG; }
	const IDs getID() const;
	//void setWindow(sf::RenderWindow* window) { pWindow = window;}
	virtual void draw() = 0;
	
};

