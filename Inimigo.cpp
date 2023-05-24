#include "Inimigo.h"


#define INIMIGO_VIDA 5

Entidades::Personagens::Inimigo::Inimigo() //: Personagem(INIMIGO_VIDA)
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Entidades::Personagens::Inimigo::~Inimigo()
{
}
