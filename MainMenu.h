#pragma once
#include "Menu.h"
#include "Background.h"

#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

class MainMenu :
    public Menu
{
private:
    Background fundo;
    bool leave;
    void createBackground();
    void createButton();
public:
    MainMenu();
    ~MainMenu();
    void setLeave(const bool sair = true);
    const bool getLeave() const;
    //void mudarEstadoObservador();
    void executar();
};

