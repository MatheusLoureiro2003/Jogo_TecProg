#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Entidade.h"
#include "Ente.h"
#include "ListaEntidades.h"
#include "Fase.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Estados.h"



class Jogo
{
private:
	static Gerenciadores::Gerenciador_Eventos* pEve;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	static Gerenciadores::Gerenciador_Estados* pGE;
	void inicializa();
public:
	Jogo();
	~Jogo();
	void Executar();

};

