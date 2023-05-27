#include "SingleFrameAnimation.h"

SingleFrameAnimation::SingleFrameAnimation() :texture(nullptr)
{
}

SingleFrameAnimation::~SingleFrameAnimation()
{
}

void SingleFrameAnimation::initialize(const char* path, Matematica::CoordF position, Matematica::CoordF size)
{
	texture = pGG->loadTexture(path);

    body.setSize(sf::Vector2f(size.x, size.y));
    body.setPosition(sf::Vector2f(position.x, position.y));
    body.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
    body.setTexture(texture);
}

void SingleFrameAnimation::update(Matematica::CoordF position)
{
    body.setPosition(sf::Vector2f(position.x, position.y));
}
