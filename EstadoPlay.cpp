#include "EstadoPlay.h"

EstadoPlay::EstadoPlay(const IDs ID, Fases::Fase* fase):
	Estado(ID), fase(fase)
{
}

EstadoPlay::~EstadoPlay()
{
	if (fase) {
		delete(fase);
		fase = nullptr;
	}
}

Fases::Fase* EstadoPlay::getFase()
{
	return fase;
}

void EstadoPlay::executar()
{
	fase->Executar();
}

void EstadoPlay::changeObserverState()
{
	//desativa o observador do jogador
	fase->getJogador()->changeObserverState();
	//desativa o observador da fase
	fase->changeObserverState();
}
