#include "Entidade.h"


Entidades::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID) : Ente(ID), body(sf::RectangleShape(tam)), pos(pos), tam(tam)
{
    body.setPosition(pos);
}

Entidades::Entidade::~Entidade()
{
}

const sf::RectangleShape Entidades::Entidade::getBody()
{
    return body;
}
