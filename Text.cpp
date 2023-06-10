#include "Text.h"


Text::Text(const sf::Font font, const std::string info, const unsigned int fontSize):
	font(font), text(), info(info), textColor(sf::Color::White),
	edgeColor(sf::Color::Black), fontSize(fontSize)
{

}

Text::~Text()
{
}

void Text::inicializa()
{
    text.setString(info);
    text.setCharacterSize(fontSize);
    text.setFont(font);
    text.setOutlineThickness(5);
    text.setOutlineColor(edgeColor);
    text.setFillColor(textColor);
    tam = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
}

void Text::setColorText(const sf::Color corTexto) {
    this->textColor = corTexto;
    text.setFillColor(corTexto);
}

const sf::Text Text::getText() const
{
	return text;
}

void Text::setPos(const sf::Vector2f pos) {
    text.setPosition(pos);
}

sf::Vector2f Text::getTam() {
    return tam;
}

