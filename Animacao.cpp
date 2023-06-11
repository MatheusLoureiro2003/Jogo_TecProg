#include "Animacao.h"

Animacao::Animacao(sf::RectangleShape* corpo) :
    body(corpo), mapImage(), currentImage(""), clock()
{
}


Animacao::~Animacao()
{
    std::map<std::string, Image*>::iterator it = mapImage.begin();
    while (it != mapImage.end()) {
        if (it->second) {
            delete(it->second);
            it->second = nullptr;
        }
        it++;
    }
    mapImage.clear();
}

void Animacao::update(const bool paraEsquerda, std::string imgAtual)
{
    if (this->currentImage != imgAtual) {
        if (this->currentImage != "") {
            mapImage[this->currentImage]->reset();
        }
        this->currentImage = imgAtual;
    }
    float dt = clock.getElapsedTime().asSeconds();
    clock.restart();

    Image* img = mapImage[this->currentImage];
    sf::Vector2f tamCorpo = body->getSize();
    sf::Vector2f escala = img->getScale();

    img->update(paraEsquerda, dt);
    body->setTextureRect(img->getSize());
    body->setTexture(img->getTexture());
    body->setScale(escala.x, escala.y);
}

void Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala)
{
    Image* img = new Image(caminhoTextura, qtdImagem, tempoTroca, escala);
    mapImage.insert(std::pair<std::string, Image*>(nomeAnimacao, img));
}
