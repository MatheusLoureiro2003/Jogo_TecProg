#include "Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Estados* Gerenciadores::Gerenciador_Estados::Instance = nullptr;

Gerenciadores::Gerenciador_Estados::Gerenciador_Estados():
	pilhaEstados(), construtorEstado()
{
}

Gerenciadores::Gerenciador_Estados::~Gerenciador_Estados()
{
    //delete stack states
    while (!pilhaEstados.empty()) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }

    if (Instance) {
        delete(Instance);
        Instance = nullptr;
    }
}

Gerenciadores::Gerenciador_Estados* Gerenciadores::Gerenciador_Estados::getInstance()
{
	if (Instance == nullptr) {
		Instance = new Gerenciadores::Gerenciador_Estados();
	}
	return Instance;
}

void Gerenciadores::Gerenciador_Estados::executar()
{
    if (!pilhaEstados.empty()) {
        pilhaEstados.top()->executar();
    }
}

void Gerenciadores::Gerenciador_Estados::addState(const IDs ID)
{
    Estado* estado = nullptr;// construtorEstado.createState(ID);
    if (estado == nullptr) {
        std::cout << "ERROR::Gerenciador::Gerenciador_Estado::estado é nullptr" << std::endl;
        exit(1);
    }
    //if (!pilhaEstados.empty()) {desativarObservadores();}
    //arrumar...
    pilhaEstados.push(estado);
}

void Gerenciadores::Gerenciador_Estados::removeState()
{
    if (pilhaEstados.top() != nullptr) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
   // if (!pilhaEstados.empty()) {ativarObservadores();}
    else {
        Gerenciador_Grafico* pGG = pGG->getInstance();
        pGG->closeWindow();
    }
}

Estado* Gerenciadores::Gerenciador_Estados::getCurrentState()
{
    return pilhaEstados.top();
}
