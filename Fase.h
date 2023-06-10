#pragma once
#include "ListaEntidades.h"
#include "Ente.h"
#include"Background.h"
#include "Construtor_Entidades.h"
#include <fstream>


namespace Observadores {
	class ObserverFase;
}

namespace Fases {
	class Fase :
		public Ente
	{
	private:
		Observadores::ObserverFase* observadorFase;
	protected:
		Listas::ListaEntidades listaPersonagens;
		//Listas::ListaEntidades listaObstaculos;
		Construtor::Construtor_Entidades construtorEntidade;

		Background background;

		void updateEntities();

	public:
		Fase(const IDs ID_Fase, const IDs ID_Fundo);
		~Fase();
		Entidades::Personagens::Jogador* getJogador();
		void Executar();
		void draw();
		virtual void createBackground() = 0;
		virtual void createMap() = 0;
		void changeObserverState();
		void createEntities(char letra, const sf::Vector2i pos);
	};
}
