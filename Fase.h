#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include "Ente.h"

namespace Fases {
	class Fase :
		public Ente
	{
	protected:
		Listas::ListaEntidades* listaEntidades;
		Entidades::Personagens::Inimigo* i1;
		Entidades::Personagens::Jogador* j1;


	public:
		Fase();
		virtual ~Fase();
		virtual void inicializaElementos() = 0;
		virtual Listas::ListaEntidades* getListaEntidades() { return listaEntidades; }
		void draw() {
			for (int i = 0; i < listaEntidades->getLen(); i++) {
				Entidade::Entidade* temp = listaEntidades->getItem(i);
				temp->draw();
			}
		}
	};
}
