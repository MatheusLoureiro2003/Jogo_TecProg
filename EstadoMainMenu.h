#pragma once
#include "MainMenu.h"

#include "Estado.h"
class EstadoMainMenu :
    public Estado
{
private:
    Menus::MainMenu mainMenu;
public:
    EstadoMainMenu();
    ~EstadoMainMenu();
    void changeObserverState();
    void executar();
};

