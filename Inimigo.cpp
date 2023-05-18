#include "Inimigo.h"

Entidades::Inimigo::Inimigo()
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Entidades::Inimigo::~Inimigo()
{
}
