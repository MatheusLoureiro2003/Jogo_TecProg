#include "Construtor_Entidades.h"

Construtor::Construtor_Entidades::Construtor_Entidades(Entidades::Personagens::Jogador* pjogador1):
	pjogador1(pjogador1)
{
}

Construtor::Construtor_Entidades::Construtor_Entidades():
	pjogador1(pjogador1)
{
}

Construtor::Construtor_Entidades::~Construtor_Entidades()
{
}

void Construtor::Construtor_Entidades::verificaJogador()
{
	if (pjogador1 == nullptr) {
		throw "ERROR::Construtor::Contrutor_Entidade::pjogador1 é nullptr";
	}
}

Entidades::Entidade* Construtor::Construtor_Entidades::createEnemy(const sf::Vector2f pos, const sf::Vector2f tam)
{
    verificaJogador();
    Entidades::Personagens::Inimigo* inimigo = new Entidades::Personagens::Inimigo(pos, tam, pjogador1);
    if (inimigo == nullptr) {
        std::cout << "Construtor::Construtor_Fase::nao foi possivel criar um inimigo" << std::endl;
        exit(1);
    }
    return static_cast<Entidades::Entidade*>(inimigo);
}

Entidades::Entidade* Construtor::Construtor_Entidades::createPlayer(const sf::Vector2f pos, bool first)
{
    Entidades::Personagens::Jogador* jogador1 = new Entidades::Personagens::Jogador(pos,first);
    if (jogador1 == nullptr) {
        std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    if (pjogador1 == nullptr) {
        pjogador1 = jogador1;
    }
    return static_cast<Entidades::Entidade*>(jogador1);
}
