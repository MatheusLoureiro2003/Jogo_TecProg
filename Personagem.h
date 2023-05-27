#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Personagem :
			public Entidade::Entidade
		{
		protected:
		public:
			Personagem();
			virtual ~Personagem();
			virtual void atualizar() = 0;
			//virtual int getVidas() const = 0;
		};
	}
}

