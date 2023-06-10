#include "Jogador.h"
#include <cmath>
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisao.h"

Entidades::Personagens::Jogador::Jogador(const sf::Vector2f pos,bool first) :
    Entidades::Personagens::Personagem(VELOCIDADE_JOGADOR, pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), IDs::jogador), 
    first(first)
{
    //body.setPosition(pos);//(sf::Vector2f(100.f, 200.f));
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

void Entidades::Personagens::Jogador::setFirst(const bool first)
{
    this->first = first;
}

bool Entidades::Personagens::Jogador::getFirst()
{
    return first;
}

void Entidades::Personagens::Jogador::inicializa()
{
    body.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}
