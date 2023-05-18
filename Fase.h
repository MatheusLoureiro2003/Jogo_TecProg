#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Entidade.h"
class Fase
{
private:
	ListaEntidades *listaEntidades;
	Entidades::Inimigo* i1;
	Entidades::Jogador* j1;
	sf::RenderWindow* window;

	void inicializaElementos();
public:
	Fase(Entidades::Jogador* j1, sf::RenderWindow* window);
	~Fase();
	ListaEntidades* getListaEntidades() { return listaEntidades; }
};

