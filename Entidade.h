#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidade {
	class Entidade :
		public Ente
	{
	protected:
		sf::RectangleShape body;
		int x;
		int y;
	public:
		Entidade();
		~Entidade();
		//virtual void executar() = 0;
		void draw() { pGG->draw(body); }
	};
}

	

