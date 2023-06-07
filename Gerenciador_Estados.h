#pragma once
//Construtor
#include "Construtor_Estado.h"

//Gerenciadores
#include "Gerenciador_Grafico.h"

//Pilha
#include <stack>

namespace Gerenciadores {
	class Gerenciador_Estados
	{
    private:
        std::stack<Estado::Estado*> pilhaEstados;
        Construtor::ConstrutorEstado construtorEstado;
        static GerenciadorMusica* pMusica;

        //padr�o de projeto singleton
        static GerenciadorEstado* pGerenciadorEstado;
        GerenciadorEstado();

        void desativarObservadores();
        void ativarObservadores();
    public:
        ~GerenciadorEstado();
        static GerenciadorEstado* getGerenciadorEstado();
        void executar();
        void addEstado(const IDs::IDs ID);
        void removerEstado();
        Estado::Estado* getEstadoAtual();
	};
}
