#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Personagem :
			public Entidades::Entidade
		{
		protected:
			sf::Vector2f lastSpeed;
			bool canWalk;
			bool toLeft;
			sf::Vector2f Speed;
			//bool canWalk;
			//bool toLeft;
			sf::Clock relogio;
			float dt;
		public:
			Personagem(const float speed, const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID);
			virtual ~Personagem();
			void Walk(const bool toLeft);
			void Stop();
			void updatePosition();
			virtual void atualizar() = 0;
			//virtual int getVidas() const = 0;
		};
	}
}

