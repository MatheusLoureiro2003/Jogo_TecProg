#include "EstadoMenuPause.h"

#include "Gerenciador_Estados.h"

EstadoMenuPause::EstadoMenuPause():
Estado(IDs::estado_menu_pausa), estadoJogar(nullptr), menuPause()
{
    Estado* actualState = pGE->getActualState();
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

void EstadoMenuPause::executar()
{
    menuPause.executar();
}
