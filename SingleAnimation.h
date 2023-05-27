#pragma once
#include "Animacao.h"

class SingleAnimation :
    public Animacao
{
private:
    const unsigned int imageCount;
    unsigned int currentImage;
    sf::Texture* texture;
    float totalTime;
    sf::IntRect rectSize;
    const float switchTime;

public:
    SingleAnimation(const char* path, const unsigned int imageCount, const float switchTime);

    ~SingleAnimation();

    void update(const float dt, bool facingLeft);

    void reset();

    sf::IntRect getSize() const;

    sf::Texture* getTexture() const;
};

