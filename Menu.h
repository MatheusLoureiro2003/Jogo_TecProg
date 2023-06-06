#pragma once
#include "Ente.h"
#include "Botao.h"
#include <list>

class Menu :
    public Ente
{
protected:
    std::list<Botao::Botao*> ButtonList;
    std::list<Botao::Botao*>::iterator it;
    const sf::Vector2f ButtonSize;
    const sf::Vector2f WindowSize;
    sf::Vector2f BackPosition;
    Botao::Texto MenuName;
    bool MouseSelected = false;

    void UpdateBackPosition();
};

