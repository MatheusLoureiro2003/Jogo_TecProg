#include "Layer.h"

Layer::Layer(const sf::Vector2f tamJanela, sf::Texture textura, const float vel):
WindowSize(tamJanela), texture(textura), dimension(0, 0, 0, 0), vel(vel)
{
    dimension.width = -abs(static_cast<int>(textura.getSize().x)); //olhar futuramente
    dimension.height = textura.getSize().y;
    dimension.left = textura.getSize().x;
    background.setSize(tamJanela);
    background.setTexture(&this->texture);
    background.setPosition(0.0f, 0.0f);

    auxBackground.setSize(tamJanela);
    auxBackground.setTexture(&this->texture);
    auxBackground.setPosition(tamJanela.x, 0.0f);
}

Layer::~Layer()
{
}

void Layer::drawLayer(sf::RenderWindow* window)
{
    window->draw(background);
    if (vel != 0.0f) {
        window->draw(auxBackground);
    }
}

void Layer::update(const sf::Vector2f ds, const sf::Vector2f posCameraAtual)
{
    const float posDireita = posCameraAtual.x + WindowSize.x / 2.0f;
    const float posEsquerda = posCameraAtual.x - WindowSize.x / 2.0f;

    if (vel != 0.0f) {
        const sf::Vector2f posFundo = background.getPosition();
        const sf::Vector2f posFundoAux = auxBackground.getPosition();

        //aplicando o movimento contrário para as camadas
        background.move(ds.x * -vel, 0.0f);
        auxBackground.move(ds.x * -vel, 0.0f);

        if (ds.x > 0.0f) { // camera movendo para a direita
            if (posFundo.x + WindowSize.x < posEsquerda) {
                changeTexture();
                background.setPosition(posEsquerda, 0.0f);
                auxBackground.setPosition(posDireita, 0.0f);
            }

        }
        else { // camera movendo para a esquerda
            if (posFundo.x > posEsquerda) {
                changeTexture();
                background.setPosition(posEsquerda - WindowSize.x, 0.0f);
                auxBackground.setPosition(posEsquerda, 0.0f);
            }
        }
    }
    else {
        background.setPosition(posEsquerda, 0.0f);
    }
}

void Layer::changeTexture()
{
    sf::RectangleShape change = background;
    background = auxBackground;
    auxBackground = change;
}
