#include "Fase.h"

Fase::Fase(Entidades::Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	//i1 = new Personagem::Inimigo();
	i1->setWindow(window);
	inicializaElementos();
}

Fase::~Fase()
{
}

void Fase::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}

