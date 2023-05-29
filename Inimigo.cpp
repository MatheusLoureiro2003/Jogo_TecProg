#include "Inimigo.h"




Entidades::Personagens::Inimigo::Inimigo() : 
	Personagem(VELOCIDADE_INIMIGO)
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Entidades::Personagens::Inimigo::~Inimigo()
{
}

void Entidades::Personagens::Inimigo::atualizar()
{
}
