#pragma once
#include "Observer.h"
#include "MenuPause.h"


namespace Observadores {
    class ObserverMenuPause :
        public Observer
    {
    private:
        Menu::MenuPause* menuPausa;
    public:
        ObserverMenuPause(Menu::MenuPause* menuPausa);
        ~ObserverMenuPause();
        void isKeyPressed(const sf::Keyboard::Key tecla);
        void isKeyLoose(const sf::Keyboard::Key tecla);
        void moveMouse(const sf::Vector2f posMouse);
        void buttonLooseMouse(const sf::Mouse::Button botaoMouse);
    };
}
