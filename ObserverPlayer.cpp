#include "ObserverPlayer.h"

Observadores::ObserverPlayer::ObserverPlayer(Entidades::Personagens::Jogador* pJogador):
	Observer(), pJogador(pJogador)
{
}

Observadores::ObserverPlayer::~ObserverPlayer()
{
}

void Observadores::ObserverPlayer::IsKeyPressed(const sf::Keyboard::Key tecla)
{
	
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

void Observadores::ObserverPlayer::IsKeyLoose(const sf::Keyboard::Key tecla)
{
    
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
