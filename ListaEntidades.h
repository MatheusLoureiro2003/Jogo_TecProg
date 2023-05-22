#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
public:
	Lista<Entidade> LEs;
	int getLen() { return LEs.getLen(); }
	Entidade* getItem(int i) { return LEs.getItem(i); }
};

