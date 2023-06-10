#pragma once
#include <SFML/Graphics.hpp>

class Layer
{
private:
    const sf::Vector2f WindowSize;
    sf::IntRect dimension;
    const float vel;

    sf::Texture texture;
    sf::RectangleShape background;
    sf::RectangleShape auxBackground;

    void changeTexture();
public:
    Layer(const sf::Vector2f tamJanela, sf::Texture textura, const float vel);
    ~Layer();
    void drawLayer(sf::RenderWindow* window);
    void update(const sf::Vector2f ds, const sf::Vector2f posCameraAtual);
};

