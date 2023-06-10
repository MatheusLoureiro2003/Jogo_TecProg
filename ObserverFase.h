#pragma once
#include "Observer.h"
#include "Fase.h"

namespace Observadores {

    class ObserverFase :
        public Observer
    {
    private:
        Fases::Fase* fase;
    public:
        ObserverFase(Fases::Fase* fase);
        ~ObserverFase();
        void isKeyPressed(const sf::Keyboard::Key tecla);
        void isKeyLoose(const sf::Keyboard::Key tecla);
    };
}
