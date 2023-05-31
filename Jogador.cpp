#include "Jogador.h"
#include <cmath>
#include "Gerenciador_Eventos.h"
#include "Colisor.h"

Entidades::Personagens::Jogador::Jogador() :
    Entidades::Personagens::Personagem(200.0f)
{
    static Gerenciadores::Gerenciador_Eventos* pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
    pEve->setJogador(this);
    body.setPosition(sf::Vector2f(100.f, 200.f));
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
   
    updatePosition();
    
    relogio.restart();
   
}
