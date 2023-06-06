#pragma once
#include <SFML\Graphics.hpp>

class Text
{
private:
    const sf::Font font;
    std::string info;
protected:
    sf::Text text;
    sf::Vector2f tam;
    unsigned int fontSize;
    sf::Color textColor;
    sf::Color edgeColor;

    void inicializa();
public:
    Text(const sf::Font font, const std::string info, const unsigned int fontSize = 50);
    ~Text();
    const sf::Text getText() const;
    void setPos(const sf::Vector2f pos);
    sf::Vector2f getTam();
    void setColorText(const sf::Color corTexto);
};

