#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Ente.h"
#include"Background.h"
#include "Construtor_Entidades.h"
namespace Gerenciadores { class Gerenciador_Evento; }

namespace Fases {
	class Fase :
		public Ente
	{
	protected:
		//Listas::ListaEntidades* listaEntidades;
		Listas::ListaEntidades listaPersonagens;
		Listas::ListaEntidades listaObstaculos;
		Construtor::Construtor_Entidades construtorEntidade;
		Entidades::Personagens::Inimigo* i1;
		Entidades::Personagens::Jogador* j1;
		Entidades::Personagens::Jogador* j2;
		Background background;

	public:
		Fase(const IDs ID_Fase, const IDs ID_Fundo);
		~Fase();
		void inicializaElementos();
		Entidades::Personagens::Jogador* getJogador();
		Listas::ListaEntidades* getListaEntidades();
		void Executar();
		void draw();
		virtual void createBackground() = 0;
		virtual void createMap() = 0;
	};
}
