#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"

class Image
{
private:
    static Gerenciadores::Gerenciador_Grafico* pGG;
    sf::Texture texture;
    sf::IntRect size;
    const sf::Vector2f scale;
    const unsigned int qtdImage;
    unsigned int currentImage;
    const float timeChange;
    float totalTime;
public:
    Image(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
    ~Image();
    void update(const bool paraEsquerda, const float dt);
    void reset();
    const sf::IntRect getSize() const;
    const sf::Texture* getTexture() const;
    const sf::Vector2f getScale() const;
};

