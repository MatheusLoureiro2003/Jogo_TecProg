#pragma once
#include "Animacao.h"
class SingleFrameAnimation :
    public Animacao
{
private:
    sf::Texture* texture;
public:
    SingleFrameAnimation();

    virtual ~SingleFrameAnimation();

    void initialize(const char* path, Matematica::CoordF position, Matematica::CoordF size);

    void update(Matematica::CoordF position);
};

