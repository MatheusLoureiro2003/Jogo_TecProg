#include "Personagem.h"



Entidades::Personagens::Personagem::Personagem(const float speed, const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID):
Entidade(pos, tam,ID),
canWalk(false), toLeft(false), relogio(), attack(false), dt(0.0f),
lastSpeed(sf::Vector2f(speed, 0.0f)),maxSpeed(speed), animacao(&body)
{
}

Entidades::Personagens::Personagem::~Personagem()
{
}

void Entidades::Personagens::Personagem::Walk(const bool toLeft)
{
	attack = false;
	canWalk = true;
	this->toLeft = toLeft;
	
}

void Entidades::Personagens::Personagem::Stop()
{
	canWalk = false;
}

void Entidades::Personagens::Personagem::Attack(const bool attack)
{
	canWalk = false;
	this->attack = attack;
}

void Entidades::Personagens::Personagem::updatePosition()
{
	dt = relogio.getElapsedTime().asSeconds();

    if (dt > 0.3) {
        dt = 0.0f;
    }
    relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    //move na horizontal
    if (canWalk) {
        ds.x = lastSpeed.x * dt;
        if (toLeft) {
            ds.x *= -1;
        }
    }

    //sofre o efeito da gravidade
    lastSpeed.y += GRAVIDADE * dt;
    ds.y = lastSpeed.y * GRAVIDADE;

    //atualiza posição
    setPos(sf::Vector2f(pos.x + ds.x, pos.y + ds.y));

    //atualiza velocidade na horizontal
    lastSpeed.x = maxSpeed;

    //desenha na janela
    draw();
}

void Entidades::Personagens::Personagem::updateAnimation()
{
    if (canWalk) {
        animacao.update(toLeft, "ANDA");
    }
    else {
        animacao.update(toLeft, "PARADO");
    }
}

