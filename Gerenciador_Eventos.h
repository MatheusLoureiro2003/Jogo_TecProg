#pragma once
#include "jogador.h"
#include "Inimigo.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Estados.h"

namespace Gerenciadores {
	class Gerenciador_Eventos
	{
	private:

		static Gerenciador_Eventos* instance;
		static Gerenciador_Grafico* pGG;
		static Gerenciador_Estados* pGE;
		Entidades::Personagens::Jogador* pj1;
		Entidades::Personagens::Jogador* pj2;
		//Entidades::Personagens::Inimigo* pI1;
		//padrão de projeto singleton
		Gerenciador_Eventos();
	public:
		static Gerenciador_Eventos* getInstance();
		~Gerenciador_Eventos();
		void setJogador(Entidades::Personagens::Jogador* pj1, Entidades::Personagens::Jogador* pj2);
		//void setInimigo(Entidades::Personagens::Inimigo* pI1);
		void isKeyPressed(const sf::Keyboard::Key tecla, bool first);
		void isKeyLoose(const sf::Keyboard::Key tecla, bool first);
		void executar();
	};
}
