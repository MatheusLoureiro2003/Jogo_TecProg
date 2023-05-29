#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {
	class Entidade :
		public Ente
	{
	protected:
		sf::RectangleShape body;
		sf::Vector2f pos;
		sf::Vector2f tam;
		int x;
		int y;
	public:
		Entidade();
		~Entidade();
		virtual void atualizar() = 0;
		//virtual void executar() = 0;
		void draw() { pGG->draw(body); }
	};
}

	

