#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"


Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::instance = nullptr;

Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Eventos::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Estados* Gerenciadores::Gerenciador_Eventos::pGE = Gerenciadores::Gerenciador_Estados::getInstance();

Listas::ListaObserver* Gerenciadores::Gerenciador_Eventos::listaObservador = nullptr;

Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Gerenciador_Eventos();
        }
        return instance;
    }

Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos()
{
    listaObservador = new Listas::ListaObserver();
    if (listaObservador == nullptr) {
        std::cout << "ERROR:::Gerenciadores::Gerenciador_Eventos::nao foi possivel criar uma Lista de Observadores" << std::endl;
        exit(1);
    }
}

Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos()
{
    if (listaObservador) {
        delete(listaObservador);
        listaObservador = nullptr;
    }
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
void Gerenciadores::Gerenciador_Eventos::executar()
{
    sf::Event evento;
    while (pGG->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed) {
            listaObservador->isKeyPressed(evento.key.code);
            listaObservador->isKeyPressed(evento.key.code);
        }
        else if (evento.type == sf::Event::KeyReleased) {
            listaObservador->isKeyLoose(evento.key.code);
            listaObservador->isKeyLoose(evento.key.code);
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


