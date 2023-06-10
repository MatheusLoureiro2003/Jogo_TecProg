#include "Fase.h"
#include "ObserverFase.h"


void Fases::Fase::updateEntities()
{
}

Fases::Fase::Fase(const IDs ID_Fase, const IDs ID_Fundo):Ente(ID),
background(ID_Fundo), listaPersonagens(),
listaObstaculos(), construtorEntidade(), observadorFase(new Observadores::ObserverFase(this))
{

}

Fases::Fase::~Fase()
{
	listaObstaculos.limparLista();
	listaPersonagens.limparLista();
	if (observadorFase) {
		delete(observadorFase);
		observadorFase = nullptr;
	}
}

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

void Fases::Fase::Executar()
{
	background.executar();
	listaPersonagens.executar();
}

void Fases::Fase::draw()
{
	listaPersonagens.desenharEntidades();

}

void Fases::Fase::changeObserverState()
{
	observadorFase->changeStateActivate();
}



//j1 = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 200.f),false);
//j2 = new Entidades::Personagens::Jogador(sf::Vector2f(500.f, 200.f), true);
//listaEntidades = new Listas::ListaEntidades();
//i1 = new Entidades::Personagens::Inimigo(sf::Vector2f(100.f, 200.f), sf::Vector2f(100.f, 200.f),j1);

//Background.initialize("./Assets/Background/CyberPunkBackGround.jfif", Matematica::CoordF(1280 / 2, 720 / 2), Matematica::CoordF(1280, 720));
//inicializaElementos();
//static Gerenciadores::Gerenciador_Eventos* pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
//pEve->setJogador(j1,j2);