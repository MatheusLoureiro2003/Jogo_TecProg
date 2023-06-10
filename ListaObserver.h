#pragma once
#include "Lista.h"
#include "Observer.h"
#include "SFML\Graphics.hpp"

namespace Listas {
    class ListaObserver
    {
    private:
        Listas::Lista<Observadores::Observer> objListaObservador;
    public:
        ListaObserver();
        ~ListaObserver();
        void addObserver(Observadores::Observer* observador);
        void removeObserver(Observadores::Observer* observador);
        void removeObserver(int pos);
        int getTam();
        Observadores::Observer* operator[](int pos);
        void isKeyPressed(const sf::Keyboard::Key tecla, bool first);
        void isKeyLoose(const sf::Keyboard::Key tecla, bool first);
        void notifyMouseMovement(const sf::Event::MouseMoveEvent mouse);
        void notifyMouseButtonRealeased(const sf::Mouse::Button botaoMouse);
    };
}

