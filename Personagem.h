#pragma once
#include "Entidade.h"

class Personagem : 
	public Entidade
{
protected:
	int num_Vidas;

public:
	Personagem();
	~Personagem();
	int getVidas() const { return num_Vidas; }
};


