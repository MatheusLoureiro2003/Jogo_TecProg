#pragma once
#include "Lista.h"
#include "Entidade.h"
namespace Listas {
	class ListaEntidades
	{
	private:
		Listas::Lista<Entidade::Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void addEntidade(Entidade::Entidade* entidade);
		void removerEntidade(Entidade::Entidade* entidade);
		void removerEntidade(int pos);
		int getLen() { return LEs.getLen(); }
		Entidade::Entidade* getItem(int i) { return LEs.getItem(i); }
		void limparLista();
		void executar();
		void desenharEntidades();
	};
}
