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
		Entidade(const sf::Vector2f pos, const sf::Vector2f tam);
		~Entidade();
		virtual void atualizar() = 0;
		const sf::RectangleShape getBody();
		//virtual void executar() = 0;
		void draw() { pGG->draw(body); }
	};
}

	

