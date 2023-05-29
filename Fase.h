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
	private:
		Listas::ListaEntidades* listaEntidades;
		Entidades::Personagens::Inimigo* i1;
		Entidades::Personagens::Jogador* j1;

	public:
		Fase();
		~Fase();
		void inicializaElementos();
		Listas::ListaEntidades* getListaEntidades();
		void Executar();
		void draw();
	};
}
