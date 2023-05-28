#include "Fase.h"


Fases::Fase::Fase(Entidades::Personagens::Jogador* j1)
{
	this->j1 = j1;
	listaEntidades = new Listas::ListaEntidades();
	i1 = new Entidades::Personagens::Inimigo();
	Background.initialize("./Assets/Background/CyberPunkBackGround.jfif", Matematica::CoordF(1280 / 2, 720 / 2), Matematica::CoordF(1280, 720));
	inicializaElementos();
}

Fases::Fase::~Fase()
{
}

void Fases::Fase::inicializaElementos()
{
	listaEntidades->addEntidade(j1);
	listaEntidades->addEntidade(i1);
}

void Fases::Fase::Executar()
{
	listaEntidades->executar();
}

void Fases::Fase::draw()
{
	Background.draw();
	listaEntidades->desenharEntidades();
}

