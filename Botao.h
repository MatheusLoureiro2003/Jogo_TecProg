#pragma once

#include "Ente.h"
#include "AnimatedText.h"
#define TEMPO_TROCAR_COR 0.01f
#define CAMINHO_FONTE "C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/ThaleahFat.ttf"


class Botao :
    public Ente
{
protected:
    sf::RectangleShape TextBox;
    AnimatedText text;
    sf::Vector2f pos;
    sf::Vector2f tam;
    bool selected;
    const sf::Color colorSelected;

    sf::Clock Clock;
    const float timeChangeColor;
    float time;

    const sf::Vector2f getTextSize() const;
public:
    Botao(const std::string info, const sf::Vector2f tam, const sf::Vector2f pos, const IDs ID, const sf::Color corSelecionado);//const IDs::IDs ID
    virtual ~Botao();
    virtual void draw();
    void updateText();
    void setSelecionado(const bool selecionado = true);
    const bool getSelecionado() const;
    void updatePosition(const sf::Vector2f pos);
    const sf::Vector2f getPos() const;
};

