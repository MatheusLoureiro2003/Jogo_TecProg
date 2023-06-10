#include "Background.h"

Background::Background(const IDs ID):
	Ente(ID), lastCameraPos(pGG->getCamera().getCenter()),
	layer()
{
}

Background::~Background()
{
    for (int i = 0; i < layer.size(); i++) {
        Layer* layers = layer.at(i);
        if (layers) {
            delete(layers);
            layers = nullptr;
        }
    }
    layer.clear();
}

void Background::draw()
{
    for (int i = 0; i < layer.size(); i++) {
        Layer* layers = layer.at(i);
        layers->drawLayer(pGG->getWindow());
    }
}

void Background::addLayer(const char* path, const float vel)
{
    Layer* layers = new Layer((sf::Vector2f)pGG->getWindow()->getSize(), pGG->loadTexture(path), vel);
    if (layers == nullptr) {
        std::cout << "ERRO::Fundo::nao foi possivel criar uma camada" << std::endl;
        exit(1);
    }
    layer.push_back(layers);
}

void Background::executar()
{
    sf::Vector2f posCamera = pGG->getCamera().getCenter();
    sf::Vector2f ds = posCamera - lastCameraPos;
    lastCameraPos = posCamera;
    if (ds.x != 0.0f) {
        ds.x *= 0.5f;
        for (int i = 0; i < layer.size(); i++) {
            layer.at(i)->update(ds, posCamera);
        }
    }
    draw(); 
}
