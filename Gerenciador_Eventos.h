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
		//padr�o de projeto singleton
		Gerenciador_Eventos();
	public:
		static Gerenciador_Eventos* getInstance();
		~Gerenciador_Eventos();
		void setJogador(Entidades::Personagens::Jogador* pj1);
		void isKeyPressed(const sf::Keyboard::Key tecla);
		void isKeyLoose(const sf::Keyboard::Key tecla);
		void executar();
	};
}
