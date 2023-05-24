#include "Jogador.h"


#define JOGADOR_VIDA 5

Entidades::Personagens::Jogador::Jogador() //:Personagem(JOGADOR_VIDA)
{
}

Entidades::Personagens::Jogador::~Jogador()
{
}

void Entidades::Personagens::Jogador::move()
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
}
