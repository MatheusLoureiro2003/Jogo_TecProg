#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include "Ente.h"
class Fase :
	public Ente
{
protected:
	ListaEntidades *listaEntidades;
	Inimigo* i1;
	Jogador* j1;

	
public:
	Fase();
	virtual ~Fase();
	virtual void inicializaElementos() = 0;
	virtual ListaEntidades* getListaEntidades() { return listaEntidades; }
	void draw() {
		for (int i = 0; i < listaEntidades->getLen(); i++) {
			Entidade* temp = listaEntidades->getItem(i);
			temp->draw();
		}
	}
};

