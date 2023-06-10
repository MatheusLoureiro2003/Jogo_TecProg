#pragma once
#include "SFML\Graphics.hpp"

namespace Gerenciadores {
    class Gerenciador_Evento;
    class Gerenciador_Estado;
}
namespace Observadores {

    class Observer
    {
    protected:
        static Gerenciadores::Gerenciador_Evento* pEve;
        static Gerenciadores::Gerenciador_Estado* pGE;
    private:
        bool activate;
    public:
        Observer();
        virtual ~Observer();
        void changeStateActivate();
        const bool getActivate() const;
        void removeObserver();
        virtual void isKeyPressed(const sf::Keyboard::Key tecla, bool first) = 0;
        virtual void isKeyLoose(const sf::Keyboard::Key tecla, bool first) = 0;
        virtual void moveMouse(const sf::Vector2f posMouse);
        virtual void buttonLooseMouse(const sf::Mouse::Button botaoMouse);
    };
}

