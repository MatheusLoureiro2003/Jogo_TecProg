#pragma once
#include "Text.h"

class AnimatedText :
    public Text
{
private:
    int transparent;
    bool lightening;
    void update();
public:
    AnimatedText(const sf::Font fonte, const std::string info);
    ~AnimatedText();
    void changeLightening();
    const bool getLightening() const;
    const int  getTransparent() const;
    void setTransparent(int transparente);
    void reset();
};

