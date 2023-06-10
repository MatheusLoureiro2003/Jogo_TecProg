#include "Jogador.h"
#include <cmath>
#include "ObserverPlayer.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisao.h"

Entidades::Personagens::Jogador::Jogador(const sf::Vector2f pos) :
    Entidades::Personagens::Personagem(VELOCIDADE_JOGADOR, pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), IDs::jogador), 
    observerPlayer(new Observadores::ObserverPlayer(this)),onFloor(false)
{
    if (observerPlayer == nullptr) {
        std::cout << "ERROR::Entidade::Personagem::Jogador::Jogador::nao foi possivel criar um observador para o jogador" << std::endl;
        exit(1);
    }
    inicializa();
}

Entidades::Personagens::Jogador::~Jogador()
{
    if (observerPlayer) {
        delete(observerPlayer);
        observerPlayer = nullptr;
    }
}

void Entidades::Personagens::Jogador::atualizar()
{
   
    updatePosition();
    pGG->updateCamera(sf::Vector2f(pos.x, 300.0f));
}

/*void Entidades::Personagens::Jogador::setFirst(const bool first)
{
    this->first = first;
}

bool Entidades::Personagens::Jogador::getFirst()
{
    return first;
}*/

void Entidades::Personagens::Jogador::jump()
{
    if (onFloor) {
        lastSpeed.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
        onFloor = false;
    }
}

void Entidades::Personagens::Jogador::canJump()
{
    onFloor = true;
}

void Entidades::Personagens::Jogador::changeObserverState()
{
    observerPlayer->changeStateActivate();
}

void Entidades::Personagens::Jogador::inicializa()
{
    body.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}
