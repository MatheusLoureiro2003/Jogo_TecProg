#include "Estado.h"

Estado::Estado(const IDs ID):
	Ente(ID)
{
}

Estado::~Estado()
{
}

void Estado::draw()
{
}

void Estado::setRemove(const bool remover)
{
	this->remove = remover;
}

const bool Estado::getRemove() const
{
	return remove;
}
