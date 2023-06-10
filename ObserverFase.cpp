#include "ObserverFase.h"
#include "Gerenciador_Estados.h"

Observadores::ObserverFase::ObserverFase(Fases::Fase* fase):
	Observer(), fase(fase)
{
}

Observadores::ObserverFase::~ObserverFase()
{
}

void Observadores::ObserverFase::IsKeyPressed(const sf::Keyboard::Key tecla)
{
}

void Observadores::ObserverFase::IsKeyLoose(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::Escape):
    {
        pGE->addState(IDs::estado_menu_pausa);
    }
    break;
    }
}
