#pragma once
#include "Observer.h"
#include "Jogador.h"

namespace Observadores {

    class ObserverPlayer :
        public Observer
    {
    private:
        Entidades::Personagens::Jogador* pJogador;
    public:
        ObserverPlayer(Entidades::Personagens::Jogador* pJogador);
        ~ObserverPlayer();
        void IsKeyPressed(const sf::Keyboard::Key tecla, bool first);
        void IsKeyLoosed(const sf::Keyboard::Key tecla, bool first);
    };
}
