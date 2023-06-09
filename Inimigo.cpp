#include "Inimigo.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisao.h"




void Entidades::Personagens::Inimigo::Inicializa() 
{
	Speed = sf::Vector2f(VELOCIDADE_INIMIGO_X, VELOCIDADE_INIMIGO_Y);
}

void Entidades::Personagens::Inimigo::MoveInimigo()
{      
    sf::Vector2f posJogador = jogador->getBody().getPosition();
    sf::Vector2f posInimigo = body.getPosition();
    if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
        if (posJogador.x - posInimigo.x > 0.0f) {
            Walk(false);
        }
        else {
            Walk(true);
            //chamar aqui a função bool colidir
            //
            /*if (Gerenciadores::Gerenciador_Colisao::colidir(posJogador, posInimigo, tam) == 1)
            {
                Stop();
            }else Walk(true);*/
        }
    }
    else {
        UpdateRamdomMoviment();
    }
}

Entidades::Personagens::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Entidades::Personagens::Jogador* jogador) :
	Personagem(VELOCIDADE_INIMIGO, pos, tam), dtAux(0.0f), jogador(jogador)
{

    //static Gerenciadores::Gerenciador_Eventos* pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
    //pEve->setInimigo(this);
    srand(time(NULL));
    RamdomMoviment = rand()%3;
    if (RamdomMoviment == 0) {
        Stop();
    }
    else if (RamdomMoviment == 1) {
        Walk(true);
    }
    else {
        Walk(false);
    }
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Entidades::Personagens::Inimigo::~Inimigo()
{
}

void Entidades::Personagens::Inimigo::atualizar()
{
    MoveInimigo();
    updatePosition();
    dtAux += relogio.getElapsedTime().asSeconds() * 100;
    relogio.restart();
}

void Entidades::Personagens::Inimigo::ChasePlayer(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
}

void Entidades::Personagens::Inimigo::UpdateRamdomMoviment()
{
    if (dtAux > 1.0f) {
        RamdomMoviment = rand() % 3;
        if (RamdomMoviment == 0) {
            Stop();
        }
        else if (RamdomMoviment == 1) {
            Walk(true);
        }
        else {
            Walk(false);
        }
        dtAux = 0.0f;
    }
}
