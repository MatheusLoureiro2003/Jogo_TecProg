#include "AnimatedText.h"

AnimatedText::AnimatedText(const sf::Font fonte, const std::string info):
	Text(fonte, info), lightening(true), transparent(255)
{
}

AnimatedText::~AnimatedText()
{
}

void AnimatedText::changeLightening()
{
	lightening = (lightening) ? false : true;
}

const bool AnimatedText::getLightening() const
{
	return lightening;
}

const int AnimatedText::getTransparent() const
{
	return transparent;
}

void AnimatedText::setTransparent(int transparente)
{
	this->transparent = transparente;
	update();
}

void AnimatedText::reset() {
    transparent = 255;
    update();
}

void AnimatedText::update() {
    edgeColor = sf::Color{ 0, 0, 0, (sf::Uint8)this->transparent };
    textColor = sf::Color{ textColor.r, textColor.g, textColor.b, (sf::Uint8)this->transparent };
    text.setOutlineColor(edgeColor);
    text.setFillColor(textColor);
}


