#pragma once
#include "Estado.h"
#include "MenuPause.h"

namespace Gerenciador {
    class GerenciadorEstado;
}

class EstadoPlay;

class EstadoMenuPause :
    public Estado
{
    private:
        MenuPause menuPause;
        EstadoPlay* estadoJogar;
        static Gerenciador::GerenciadorEstado* pGEstado;

    public:
        EstadoMenuPause();
        ~EstadoMenuPause();
        //void mudarEstadoObservador();
        void executar();
};

