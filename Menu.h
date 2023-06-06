#pragma once
#include "Ente.h"
#include "Botao.h"
#include "Text.h"
#include <list>
#include "IDs.h"

class Menu :
    public Ente
{
protected:
    std::list<Botao*> ButtonList;
    std::list<Botao*>::iterator it;
    const sf::Vector2f ButtonSize;
    const sf::Vector2f WindowSize;
    sf::Vector2f BackPosition;
    Text MenuName;
    bool MouseSelected = false;

    void UpdateBackPosition();
public:
    Menu(const IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte);
    ~Menu();
    void addButton(const std::string info, const sf::Vector2f pos, const IDs ID, const sf::Color corSelecionado);
    void draw();
    void selectBelow();
    void selectAbove();
    const IDs getIDBotaoSelecionado();
    void eventMouse(const sf::Vector2f posMouse);
    const bool getMouseSelected() const;
    virtual void executar() = 0;
};

