#pragma once
#include "Observer.h"
#include "MenuPause.h"
namespace Menus {
    class MenuPause;
}

namespace Observadores {

    class ObserverMenuPause :
        public Observer
    {
    private:
        Menus::MenuPause* menuPausa;
    public:
        ObserverMenuPause(Menus::MenuPause* menuPausa);
        ~ObserverMenuPause();
        void IsKeyPressed(const sf::Keyboard::Key tecla);
        void IsKeyLoose(const sf::Keyboard::Key tecla);
        void moveMouse(const sf::Vector2f posMouse);
        void buttonLooseMouse(const sf::Mouse::Button botaoMouse);
    };
}
