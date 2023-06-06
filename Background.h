#pragma once
#include "Ente.h"
class Background :
    public Ente
{

public:
    Background(const IDs ID);
    ~Background();
    void draw();
    void addLayer(const char* path, const float vel);
    void executar();
};

