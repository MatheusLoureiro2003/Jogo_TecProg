#pragma once
#include "SFML\Graphics.hpp"

namespace Gerenciadores {
    class Gerenciador_Eventos;
    class Gerenciador_Estados;
}
namespace Observadores {

    class Observer
    {
    protected:
        static Gerenciadores::Gerenciador_Eventos* pEve;
        static Gerenciadores::Gerenciador_Estados* pGE;
    private:
        bool activate;
    public:
        Observer();
        virtual ~Observer();
        void changeStateActivate();
        const bool getActivate() const;
        void removeObserver();
        virtual void IsKeyPressed(const sf::Keyboard::Key tecla);
        virtual void IsKeyLoose(const sf::Keyboard::Key tecla);
        virtual void moveMouse(const sf::Vector2f posMouse);
        virtual void buttonLooseMouse(const sf::Mouse::Button botaoMouse);
    };
}

