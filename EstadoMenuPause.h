#pragma once
#include "Estado.h"
#include "MenuPause.h"
#include "Gerenciador_Estados.h"

namespace Gerenciadores {
    class Gerenciador_Estados;
}

class EstadoPlay;

class EstadoMenuPause :
    public Estado
{
    private:
        MenuPause menuPause;
        EstadoPlay* estadoJogar;
        static Gerenciadores::Gerenciador_Estados* pGE;

    public:
        EstadoMenuPause();
        ~EstadoMenuPause();
        //void mudarEstadoObservador();
        void executar();
};

