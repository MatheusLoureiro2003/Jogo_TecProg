#pragma once
#include "Gerenciador_Grafico.h"

class Ente
{
protected:
	int Id;
	static Gerenciadores::Gerenciador_Grafico* pGG;
public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	void draw();
};

