#include "Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

Ente::Ente(const IDs ID) : ID(ID), body(sf::Vector2f(100.f, 100.f))
{	
}

Ente::~Ente()
{
    pGG = nullptr;
}

const IDs Ente::getID() const
{
    return ID;
}



