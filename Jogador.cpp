#include "Jogador.h"
#include <cmath>

Entidades::Personagens::Jogador::Jogador() :
    Entidades::Personagens::Personagem(200.0f)
{
}

Entidades::Personagens::Jogador::~Jogador()
{
}

/*void Entidades::Personagens::Jogador::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        body.move(sf::Vector2f(0.1f, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        body.move(sf::Vector2f(-0.1f, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        body.move(sf::Vector2f(0.0f, -0.1f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        body.move(sf::Vector2f(0.0f, 0.1f));
    }
}*/

void Entidades::Personagens::Jogador::atualizar()
{
    if (toLeft) {
        updatePosition();
    }
    relogio.restart();
   
}
