#pragma once
#include "jogador.h"
#include "Gerenciador_Grafico.h"
#include "ListaObserver.h"

namespace Gerenciadores {
	class Gerenciados_Estados;

	class Gerenciador_Eventos
	{
	private:

		static Listas::ListaObserver* listaObservador;
		static Gerenciador_Grafico* pGG;
		static Gerenciador_Estados* pGE;
		//padrão de projeto singleton:
		static Gerenciador_Eventos* instance;
		Gerenciador_Eventos();
	public:
		static Gerenciador_Eventos* getInstance();
		~Gerenciador_Eventos();
		void addObserver(Observadores::Observer* observador);
		void removeObserver(Observadores::Observer* observador);
		void removeObserver(int pos);
		void executar();
	};
}
