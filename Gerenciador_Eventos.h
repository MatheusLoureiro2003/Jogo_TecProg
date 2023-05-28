#pragma once
#include "jogador.h"
#include "Gerenciador_Grafico.h"

namespace Gerenciadores {
	class Gerenciador_Eventos
	{
	private:

		static Gerenciador_Eventos* instance;
		static Gerenciador_Grafico* pGG;
		Entidades::Personagens::Jogador* pj1;
		//padrão de projeto singleton
		Gerenciador_Eventos();
	public:
		static Gerenciador_Eventos* getInstance();
		~Gerenciador_Eventos();
		void setJogador(Entidades::Personagens::Jogador* pj1);
		void isKeyPressed(sf::Keyboard::Key tecla);
		void isKeyLoose(sf::Keyboard::Key tecla);
		void executar();
	};
}
