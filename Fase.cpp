#include "Fase.h"
#include "Gerenciador_Eventos.h"


Fases::Fase::Fase(const IDs ID_Fase, const IDs ID_Fundo):Ente(ID), background(ID_Fundo), listaPersonagens(), listaObstaculos(), construtorEntidade()
{
	j1 = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 200.f),false);
	j2 = new Entidades::Personagens::Jogador(sf::Vector2f(500.f, 200.f), true);
	//listaEntidades = new Listas::ListaEntidades();
	i1 = new Entidades::Personagens::Inimigo(sf::Vector2f(100.f, 200.f), sf::Vector2f(100.f, 200.f),j1);

	//Background.initialize("./Assets/Background/CyberPunkBackGround.jfif", Matematica::CoordF(1280 / 2, 720 / 2), Matematica::CoordF(1280, 720));
	//inicializaElementos();
	static Gerenciadores::Gerenciador_Eventos* pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
	pEve->setJogador(j1,j2);
}

Fases::Fase::~Fase()
{
	listaPersonagens.limparLista();
}

/*void Fases::Fase::inicializaElementos()
{
	listaEntidades->addEntidade(static_cast<Entidades::Entidade*>(j1));
	listaEntidades->addEntidade(static_cast<Entidades::Entidade*>(j2));
	listaEntidades->addEntidade(static_cast<Entidades::Entidade*>(i1));
}*/

Entidades::Personagens::Jogador* Fases::Fase::getJogador()
{
	for (int i = 0; i < listaPersonagens.getLen(); i++) {
		Entidades::Entidade* ent = listaPersonagens.getItem(i);
		if (ent->getID() == IDs::jogador) {
			return static_cast<Entidades::Personagens::Jogador*>(ent);
		}
	}
	return nullptr;
}

/*Listas::ListaEntidades* Fases::Fase::getListaEntidades()
{
	return listaEntidades; 
}*/

void Fases::Fase::Executar()
{
	background.executar();
	listaPersonagens.executar();
}

void Fases::Fase::draw()
{
	listaPersonagens.desenharEntidades();

}

