#pragma once
#include "Ente.h"
#include "Layer.h"
#include "IDs.h"


class Background :
    public Ente
{

private:
    sf::Vector2f lastCameraPos;
    std::vector<Layer*> layer;
public:
    Background(const IDs ID);
    ~Background();
    void draw();
    void addLayer(const char* path, const float vel);
    void executar();
};

