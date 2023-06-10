#pragma once
#include "Observer.h"
#include "Botao.h"

namespace Menu {
    class MainMenu;
}

namespace Observadores {

    class ObserverMainMenu :
        public Observer
    {
    private:
        Menu::MainMenu* menuPrincipal;
    public:
        ObserverMainMenu(Menu::MainMenu* menuPrincipal);
        ~ObserverMainMenu();
        void isKeyPressed(const sf::Keyboard::Key tecla);
        void isKeyLoose(const sf::Keyboard::Key tecla);
        void moveMouse(const sf::Vector2f posMouse);
        void buttonLooseMouse(const sf::Mouse::Button botaoMouse);
    };
}
