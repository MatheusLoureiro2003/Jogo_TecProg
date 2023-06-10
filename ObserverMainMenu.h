#pragma once
#include "Observer.h"
#include "Botao.h"

namespace Menus {
    class MainMenu;
}

namespace Observadores {

    class ObserverMainMenu :
        public Observer
    {
    private:
        Menus::MainMenu* menuPrincipal;
    public:
        ObserverMainMenu(Menus::MainMenu* menuPrincipal);
        ~ObserverMainMenu();
        void IsKeyPressed(const sf::Keyboard::Key tecla);
        void IsKeyLoose(const sf::Keyboard::Key tecla);
        void moveMouse(const sf::Vector2f posMouse);
        void buttonLooseMouse(const sf::Mouse::Button botaoMouse);
    };
}
