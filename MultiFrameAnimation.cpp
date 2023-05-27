#include "MultiFrameAnimation.h"

MultiFrameAnimation::MultiFrameAnimation() : 
animationMap(),
currentID(Animation_ID::idle)
{
}

MultiFrameAnimation::~MultiFrameAnimation()
{
    std::map<Animation_ID, SingleAnimation*>::iterator it;
    for (it = animationMap.begin(); it != animationMap.end(); ++it)
        delete (it->second);

    animationMap.clear();
}

void MultiFrameAnimation::addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount, const float switchTime)
{
    SingleAnimation* temp = new SingleAnimation(path, imageCount, switchTime);

    if (temp == nullptr) {
        std::cout << "ERROR: Não foi possível criar uma animação em MultiFrameAnimation::addNewAnimation!" << std::endl;
        exit(1);
    }

    animationMap.insert(std::pair<Animation_ID, SingleAnimation*>(id, temp));

    sf::IntRect rectSize = temp->getSize();

    body.setSize(sf::Vector2f(rectSize.width, rectSize.height));
    body.setOrigin(sf::Vector2f(rectSize.width, rectSize.height) / 2.0f);
}

void MultiFrameAnimation::update(Animation_ID id, bool facingLeft, Matematica::CoordF position, const float dt)
{
    if (currentID != id) {
        currentID = id;
        animationMap[currentID]->reset();
    }

    animationMap[currentID]->update(dt, facingLeft);

    body.setPosition(sf::Vector2f(position.x, position.y));
    body.setTextureRect(animationMap[currentID]->getSize());
    body.setTexture(animationMap[currentID]->getTexture());
}
