#pragma once
#include "Entidade.h"
//#include "Gerenciador_Colisao.h"
namespace Entidades {
	namespace Personagens {
		class Personagem :
			public Entidades::Entidade
		{
		protected:
			sf::Vector2f lastSpeed;
			bool canWalk;
			bool toLeft;
			bool attack;
			const float maxSpeed;
			sf::Vector2f Speed;
			sf::Clock relogio;
			float dt;
		public:
			Personagem(const float speed, const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID);
			virtual ~Personagem();
			void Walk(const bool toLeft);
			void Stop();
			void Attack(const bool attack);
			void updatePosition();
			virtual void atualizar() = 0;
			//virtual int getVidas() const = 0;
		};
	}
}

