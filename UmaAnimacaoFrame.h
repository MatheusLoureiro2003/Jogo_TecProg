#pragma once
#include "Animacao.h"
class UmaAnimacaoFrame :
    public Animacao
{
private:
    sf::Texture* texture;
public:
    UmaAnimacaoFrame();

    virtual ~UmaAnimacaoFrame();

    void initialize(const char* path);

   // void update(Math::CoordF position);
};

