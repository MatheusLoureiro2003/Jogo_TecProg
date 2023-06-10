#pragma once
#include "Menu.h"
#include "Fase.h"


#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Observadores {
    class ObserverMenuPause;
}
namespace Menus {
    class MenuPause :
        public Menu
    {
    private:
        Fases::Fase* fase;
        Observadores::ObserverMenuPause* observadorMenuPausa;
        sf::RectangleShape darkBackground;
        sf::RectangleShape painelBackground;

        void createButtons();
        void updateBackground();
        void updateMenuName();
        void updateButtons();
    public:
        MenuPause(Fases::Fase* fase = nullptr);
        ~MenuPause();
        void setFase(Fases::Fase* fase);
        void changeObserveState();
        void executar();
    };
}