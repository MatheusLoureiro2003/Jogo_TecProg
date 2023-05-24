#include "Fase1.h"

Fases::Fase1::Fase1(Entidades::Personagens::Jogador* j1)
{
	this->j1 = j1;
	listaEntidades = new Listas::ListaEntidades();
	i1 = new Entidades::Personagens::Inimigo();
	inicializaElementos();
}

Fases::Fase1::~Fase1()
{
}

void Fases::Fase1::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}
