#include "Ente.h"

Gerenciador_Grafico* Ente::pGG = Gerenciador_Grafico::getInstance();

Ente::Ente() : id(0), body(sf::Vector2f(100.f, 100.f))

{	
}

Ente::~Ente()
{
    pGG = nullptr;
}



