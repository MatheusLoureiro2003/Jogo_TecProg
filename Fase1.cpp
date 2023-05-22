#include "Fase1.h"

Fase1::Fase1(Jogador* j1)
{
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	i1 = new Inimigo();
	inicializaElementos();
}

Fase1::~Fase1()
{
}

void Fase1::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}
