#pragma once
#include "Personagem.h"

class Jogador :
    public Entidade
{
private:
public:
    Jogador();
    ~Jogador();
    void move();
 };

