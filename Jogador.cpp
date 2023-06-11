#include "Jogador.h"
#include <cmath>
#include "ObserverPlayer.h"

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
    updateAnimation();
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

void Entidades::Personagens::Jogador::updateAnimation()
{
    if (!onFloor && lastSpeed.y > 0.0f) {
        animacao.update(toLeft, "CAI");
    }
    else if (!onFloor) {
        animacao.update(toLeft, "PULA");
    }
    else if (attack) {
        animacao.update(toLeft, "ATACA");
    }
    else if (canWalk) {
        animacao.update(toLeft, "ANDA");
    }
    else {
        animacao.update(toLeft, "PARADO");
    }
}

void Entidades::Personagens::Jogador::inicializa()
{
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Walk.png", "ANDA", 6, 0.12f, sf::Vector2f(6, 2));
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Attack_2.png", "ATACA", 4, 0.1f, sf::Vector2f(6, 2));
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Idle.png", "PARADO", 7, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Jump.png", "PULA", 9, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Jump.png", "CAI", 9, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Dead.png", "MORRE", 6, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/Fire wizard/Hurt.png", "TOMA_DANO", 3, 0.15f, sf::Vector2f(6, 2));
    body.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}
