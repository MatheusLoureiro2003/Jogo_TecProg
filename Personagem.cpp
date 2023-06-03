#include "Personagem.h"
#include <iostream>

Entidades::Personagens::Personagem::Personagem(const float speed, const sf::Vector2f pos, const sf::Vector2f tam):
Entidade(pos, tam),
canWalk(false), toLeft(false), relogio(), dt(0.0f),lastSpeed(sf::Vector2f(speed, 0.0f))
{
}

Entidades::Personagens::Personagem::~Personagem()
{
}

void Entidades::Personagens::Personagem::Walk(const bool toLeft)
{
	canWalk = true;
	this->toLeft = toLeft;
	
}

void Entidades::Personagens::Personagem::Stop()
{
	canWalk = false;
}

void Entidades::Personagens::Personagem::updatePosition()
{
	dt = relogio.getElapsedTime().asSeconds();
	float ds = lastSpeed.x * dt;

	if (canWalk) {
		if (toLeft) {
			ds *= -1;
		}
		body.move(ds, 0.0f);
	}
}

