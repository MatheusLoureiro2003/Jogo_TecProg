#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"


Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::instance = nullptr;

Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Eventos::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Estados* Gerenciadores::Gerenciador_Eventos::pGE = Gerenciadores::Gerenciador_Estados::getInstance();

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
void Gerenciadores::Gerenciador_Eventos::addObserver(Observadores::Observer* observador)
{
    listaObservador->addObserver(observador);
}
void Gerenciadores::Gerenciador_Eventos::removeObserver(Observadores::Observer* observador)
{
    listaObservador->removeObserver(observador);
}
void Gerenciadores::Gerenciador_Eventos::removeObserver(int pos)
{
    listaObservador->removeObserver(pos);
}
/*
void Gerenciadores::Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2)
{
    this->pj1 = pj1;
    this->pj2 = pj2;
}

//void Gerenciadores::Gerenciador_Eventos::setInimigo(Entidades::Personagens::Inimigo* pI1)
//{
 //   this->pI1 = pI1;
//}

void Gerenciadores::Gerenciador_Eventos::isKeyPressed(const sf::Keyboard::Key tecla, bool first)
{
    if (first) {
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
    else {
        if (tecla == sf::Keyboard::Left) {
            pj2->Walk(true);
        }
        else if (tecla == sf::Keyboard::Right) {
            pj2->Walk(false);
        }
        else if (tecla == sf::Keyboard::Escape) {
            pGG->closeWindow();
        }
    }
}

void Gerenciadores::Gerenciador_Eventos::isKeyLoose(const sf::Keyboard::Key tecla, bool first)
{
    if (first) {
        if (tecla == sf::Keyboard::D || tecla == sf::Keyboard::A) {
            pj1->Stop();
        }
    }
    else
    {
        if (tecla == sf::Keyboard::Left || tecla == sf::Keyboard::Right) {
            pj2->Stop();
        }
    } 
    
}
*/
void Gerenciadores::Gerenciador_Eventos::executar()
{
    sf::Event evento;
    while (pGG->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed) {
            listaObservador->isKeyPressed(evento.key.code, pj1->getFirst());
            listaObservador->isKeyPressed(evento.key.code, pj2->getFirst());
        }
        else if (evento.type == sf::Event::KeyReleased) {
            listaObservador->isKeyLoose(evento.key.code, pj1->getFirst());
            listaObservador->isKeyLoose(evento.key.code, pj2->getFirst());
        }
        else if (evento.type == sf::Event::Closed) {
            pGG->closeWindow();
        }
        else if (evento.type == sf::Event::MouseMoved) {
            listaObservador->notifyMouseMovement(evento.mouseMove);
        }
        else if (evento.type == sf::Event::MouseButtonReleased) {
            listaObservador->notifyMouseButtonRealeased(evento.mouseButton.button);
        }
    }
}


