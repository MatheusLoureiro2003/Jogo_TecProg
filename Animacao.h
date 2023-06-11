#pragma once
#include <map>
#include "Image.h"

class Animacao
{
private:
    sf::RectangleShape* body;
    std::map<std::string, Image*> mapImage;
    sf::Clock clock;
    std::string currentImage;
public:
    Animacao(sf::RectangleShape* corpo);
    ~Animacao();
    void update(const bool paraEsquerda, std::string imgAtual);
    void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);

};

