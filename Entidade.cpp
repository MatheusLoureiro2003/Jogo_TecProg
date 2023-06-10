#include "Entidade.h"


Entidades::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID) : Ente(ID), body(sf::RectangleShape(tam)), pos(pos), tam(tam)
{
    body.setPosition(pos);
}

Entidades::Entidade::~Entidade()
{
}

void Entidades::Entidade::setPos(sf::Vector2f pos)
{
    body.setPosition(pos);
    this->pos = pos;
}

sf::Vector2f Entidades::Entidade::getPos()
{
    return pos;
}

const sf::Vector2f Entidades::Entidade::getTam()
{
    return tam;
}

const sf::RectangleShape Entidades::Entidade::getBody()
{
    return body;
}

