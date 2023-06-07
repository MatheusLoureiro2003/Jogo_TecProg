#pragma once
#include "MainMenu.h"

#include "Estado.h"
class EstadoMainMenu :
    public Estado
{
private:
    MainMenu mainMenu;
public:
    EstadoMainMenu();
    ~EstadoMainMenu();
    //void mudarEstadoObservador();
    void executar();
};

