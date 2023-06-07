#include "Fase.h"


Fases::Fase::Fase():Ente(ID)
{
	j1 = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 200.f));
	listaEntidades = new Listas::ListaEntidades();
	i1 = new Entidades::Personagens::Inimigo(sf::Vector2f(100.f, 200.f), sf::Vector2f(100.f, 200.f),j1);

	//Background.initialize("./Assets/Background/CyberPunkBackGround.jfif", Matematica::CoordF(1280 / 2, 720 / 2), Matematica::CoordF(1280, 720));
	inicializaElementos();
}

Fases::Fase::~Fase()
{
}

void Fases::Fase::inicializaElementos()
{
	listaEntidades->addEntidade(static_cast<Entidades::Entidade*>(j1));
	listaEntidades->addEntidade(static_cast<Entidades::Entidade*>(i1));
}

Listas::ListaEntidades* Fases::Fase::getListaEntidades()
{
	return listaEntidades; 
}

void Fases::Fase::Executar()
{
	listaEntidades->executar();
}

void Fases::Fase::draw()
{
	listaEntidades->desenharEntidades();
}

