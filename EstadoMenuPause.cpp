#include "EstadoMenuPause.h"

#include "Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Estados* EstadoMenuPause::pGE = Gerenciadores::Gerenciador_Estados::getInstance();

EstadoMenuPause::EstadoMenuPause():
Estado(IDs::estado_menu_pausa), estadoJogar(nullptr), menuPause()
{
    Estado* actualState = pGE->getCurrentState();
    if (actualState->getID() != IDs::jogar_cyberpunk && actualState->getID() != IDs::jogar_cyberpunk) {
        std::cout << "ERRO::Estado::EstadoMenuPausa::Estado atual não é uma fase!" << std::endl;
        exit(1);
    }
    estadoJogar = static_cast<EstadoPlay*>(actualState);
    menuPause.setFase(estadoJogar->getFase());
}

EstadoMenuPause::~EstadoMenuPause()
{
}

void EstadoMenuPause::changeObserverState()
{
    menuPause.changeObserverState();
}

void EstadoMenuPause::executar()
{
    menuPause.executar();
}
