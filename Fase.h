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
private:
	ListaEntidades *listaEntidades;
	Inimigo* i1;
	Jogador* j1;

	void inicializaElementos();
public:
	Fase(Jogador* j1);
	~Fase();
	ListaEntidades* getListaEntidades() { return listaEntidades; }
	void draw() {
		for (int i = 0; i < listaEntidades->getLen(); i++) {
			Entidade* temp = listaEntidades->getItem(i);
			temp->draw();
		}
	}
};

