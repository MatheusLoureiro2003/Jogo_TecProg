#pragma once
#include "Menu.h"
#include "Background.h"
#include "ObserverMainMenu.h"

#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Menus {
    class MainMenu :
        public Menu
    {
    private:
        Observadores::ObserverMainMenu* observadorMenuPrincipal;
        Background background;
        bool leave;
        void createBackground();
        void createButton();
    public:
        MainMenu();
        ~MainMenu();
        void setLeave(const bool sair = true);
        const bool getLeave() const;
        void changeObserverState();
        void executar();
    };
}
