#pragma once
#include "Lista.h"
#include "Entidade.h"
namespace Listas {
	class ListaEntidades
	{
	public:
		Listas::Lista<Entidade::Entidade> LEs;
		int getLen() { return LEs.getLen(); }
		Entidade::Entidade* getItem(int i) { return LEs.getItem(i); }
	};
}
