#include "Gerenciador_Eventos.h"
#include <cstring>
#include <iostream>

Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::instance = nullptr;

Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Eventos::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Gerenciador_Eventos();
        }
        return instance;
    }

Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos()
{}

Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos()
{
}

void Gerenciadores::Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* pj1)
{
    this->pj1 = pj1;
}

void Gerenciadores::Gerenciador_Eventos::isKeyPressed(const sf::Keyboard::Key tecla)
{
        if (tecla == sf::Keyboard::A) {
            pj1->Walk(true);
        }
        else if (tecla == sf::Keyboard::D) {
            pj1->Walk(false);
        }
        else if (tecla == sf::Keyboard::Escape) {
            pGG->closeWindow();
        }

}

void Gerenciadores::Gerenciador_Eventos::isKeyLoose(const sf::Keyboard::Key tecla)
{
        if (tecla == sf::Keyboard::D || tecla == sf::Keyboard::A) {
            pj1->Stop();
        }
}

void Gerenciadores::Gerenciador_Eventos::executar()
{
    sf::Event evento;
    while (pGG->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed) {
            isKeyPressed(evento.key.code);
        }
        else if (evento.type == sf::Event::KeyReleased) {
            isKeyLoose(evento.key.code);
        }
        else if (evento.type == sf::Event::Closed) {
            pGG->closeWindow();
        }
    }
}

