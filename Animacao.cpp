#include "Animacao.h"

Gerenciadores::Gerenciador_Grafico* Animacao::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Animacao::Animacao() : body()
{
}

Animacao::~Animacao()
{
}

void Animacao::draw()
{
	pGG->draw(body);
}
