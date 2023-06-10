#include "ObserverPlayer.h"

Observadores::ObserverPlayer::ObserverPlayer(Entidades::Personagens::Jogador* pJogador):
	Observer(), pJogador(pJogador)
{
}

Observadores::ObserverPlayer::~ObserverPlayer()
{
}

void Observadores::ObserverPlayer::isKeyPressed(const sf::Keyboard::Key tecla, bool first)
{
	if (first) {
        switch (tecla)
        {
        case (sf::Keyboard::A):
        {
            pJogador->Walk(true);
        }
        break;
        case (sf::Keyboard::D):
        {
            pJogador->Walk(false);
        }
        break;
        case(sf::Keyboard::W):
        {
            pJogador->jump();
        }
        break;
        case(sf::Keyboard::S):
        {
            pJogador->Attack(true);
        }
        break;;
        }
	}
    else {
        switch (tecla)
        {
        case (sf::Keyboard::Left):
        {
            pJogador->Walk(true);
        }
        break;
        case (sf::Keyboard::Right):
        {
            pJogador->Walk(false);
        }
        break;
        case(sf::Keyboard::Up):
        {
            pJogador->jump();
        }
        break;
        case(sf::Keyboard::Down):
        {
            pJogador->Attack(true);
        }
        break;;
        }
    }
}

void Observadores::ObserverPlayer::isKeyLoose(const sf::Keyboard::Key tecla, bool first)
{
    if (first) {
        switch (tecla)
        {
        case (sf::Keyboard::Left):
        {
            pJogador->Stop();
        }
        break;
        case(sf::Keyboard::Right):
        {
            pJogador->Stop();
        }
        break;
        }
    }
    else {
        switch (tecla)
        {
        case (sf::Keyboard::Left):
        {
            pJogador->Stop();
        }
        break;
        case(sf::Keyboard::Right):
        {
            pJogador->Stop();
        }
        break;
        }
    }
}
