#pragma once
#include "Gerenciador_Grafico.h"
#include <stack>
#include "Construtor_Estado.h"
#include "Estado.h"

namespace Gerenciadores {
	class Gerenciador_Estados
	{
    private:
        std::stack<Estado*> pilhaEstados;
        
        //Construtor_Estado construtorEstado;

        //padrão de projeto singleton
        static Gerenciador_Estados* Instance;
        Gerenciador_Estados();
    public:
        ~Gerenciador_Estados();
        static Gerenciador_Estados* getInstance();
        void executar();
        void addState(const IDs ID);
        void removeState();
        Estado* getCurrentState();
	};
}
