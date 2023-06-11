#include "Image.h"

Gerenciadores::Gerenciador_Grafico* Image::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

Image::Image(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala):
	qtdImage(qtdImagem), timeChange(tempoTroca),
	totalTime(0.0f), size(0, 0, 0, 0), currentImage(0), texture(pGG->loadTexture(caminhoTextura)),
	scale(escala)
{
	size.width = texture.getSize().x / (float)qtdImagem;
	size.height = texture.getSize().y;
}

Image::~Image()
{
}

void Image::update(const bool paraEsquerda, const float dt)
{
    totalTime = totalTime + dt;
    if (totalTime >= timeChange) {
        totalTime -= timeChange;
        currentImage++;
        if (currentImage >= qtdImage) {
            currentImage = 0;
        }
    }
    if (paraEsquerda) {
        size.left = (currentImage + 1) * abs(size.width);
        size.width = -abs(size.width);
    }
    else {
        size.left = currentImage * size.width;
        size.width = abs(size.width);
    }
}

void Image::reset()
{
    currentImage = 0;
    totalTime = 0.0f;
}

const sf::IntRect Image::getSize() const
{
	return size;
}

const sf::Texture* Image::getTexture() const
{
	return &texture;
}

const sf::Vector2f Image::getScale() const
{
	return scale;
}
