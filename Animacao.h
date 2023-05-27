#pragma once
#include "Gerenciador_Grafico.h"
#include "CoordenadaTL.h"
#include <SFML/Graphics.hpp>

class Animacao
{
protected:
	sf::RectangleShape body;

	static Gerenciadores::Gerenciador_Grafico* pGG;
public:
	Animacao();

	virtual ~Animacao();

	virtual void draw();

};

