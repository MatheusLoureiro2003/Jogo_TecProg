#pragma once
#include "Animacao.h"
#include "SingleAnimation.h"
#include <map>

enum Animation_ID {
    walk = 0,
    idle,
    attack,
    run,
    cooldown
};

class MultiFrameAnimation :
    public Animacao
{
private:
    std::map<Animation_ID, SingleAnimation*> animationMap;
    Animation_ID currentID;
public:
    MultiFrameAnimation();

    ~MultiFrameAnimation();

    void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount, const float switchTime = 0.2f);

    void update(Animation_ID id, bool facingLeft, Matematica::CoordF position, const float dt);
};

