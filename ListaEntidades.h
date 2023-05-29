#pragma once
#include "Lista.h"
#include "Entidade.h"
namespace Listas {
	class ListaEntidades
	{
	private:
		Listas::Lista<Entidades::Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void addEntidade(Entidades::Entidade* entidade);
		void removerEntidade(Entidades::Entidade* entidade);
		void removerEntidade(int pos);
		int getLen() { return LEs.getLen(); }
		Entidades::Entidade* getItem(int i) { return LEs.getItem(i); }
		void limparLista();
		void executar();
		void desenharEntidades();
	};
}
