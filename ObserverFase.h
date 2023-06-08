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
        void IsKeyPressed(const sf::Keyboard::Key tecla);
        void IsKeyLoosed(const sf::Keyboard::Key tecla);
    };
}
