#include "Fase.h"


Fase::Fase(Jogador* j1)
{
	
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	i1 = new Inimigo();
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

