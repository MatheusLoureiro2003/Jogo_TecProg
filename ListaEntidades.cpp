#include "ListaEntidades.h"

Listas::ListaEntidades::ListaEntidades() :
	LEs()
{
}

Listas::ListaEntidades::~ListaEntidades()
{
}

void Listas::ListaEntidades::addEntidade(Entidade::Entidade* entidade)
{
	LEs.push(entidade);
}

void Listas::ListaEntidades::removerEntidade(Entidade::Entidade* entidade)
{
	LEs.pop(entidade);
}

void Listas::ListaEntidades::removerEntidade(int pos)
{
	LEs.removerElemento(pos);
}

void Listas::ListaEntidades::limparLista()
{
	LEs.limparLista();
}

void Listas::ListaEntidades::executar()
{
	int tam = LEs.getLen();
	Entidade::Entidade* aux = nullptr;
	for (int i = 0; i < tam; i++) {
		aux = LEs.getItem(i);
		aux->atualizar();
	}
}

void Listas::ListaEntidades::desenharEntidades()
{
	int tam = LEs.getLen();
	Entidade::Entidade* aux = nullptr;
	for (int i = 0; i < tam; i++) {
		aux = LEs.getItem(i);
		aux->draw();
	}
}
