#include "Construtor_Fase.h"
namespace Construtor {
    Construtor_Fase::Construtor_Fase()
    {
    }

    Construtor_Fase::~Construtor_Fase()
    {
    }

    Fases::Fase* Construtor_Fase::createFase(const IDs ID)
    {
        Fases::Fase* fase = nullptr;
        switch (ID)
        {
        case (IDs::jogar_cyberpunk):
        {
           // fase = createCyberpunk();
        }
        break;
        case (IDs::jogar_deserto):
        {
           // fase = createDeserto();
        }
        break;
        case (IDs::jogar_espaco):
        {
           // fase = createEspaco();
        }
        break;
        default:
        {
            std::cout << "Construtor::ConstrutorFase::ID da Fase invalido" << std::endl;
            exit(1);
        }
        break;
        }
        //fase->criarFundo();
        //fase->criarMapa();
        return fase;
    }
    /*
    Fases::Fase* Construtor_Fase::criarCyberPunk()
    {
        Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::CyberPunk());
        if (fase == nullptr) {
            std::cout << "Construtor::Construtor_Fase::nao foi possivel criar Fase cyberpunk" << std::endl;
            exit(1);
        }
        return fase;
    }

    Fases::Fase* Construtor_Fase::criarDeserto()
    {
        Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Deserto());
        if (fase == nullptr) {
            std::cout << "Construtor::Construtor_Fase::nao foi possivel criar Fase deserto" << std::endl;
            exit(1);
        }
        return fase;
    }

    Fases::Fase* Construtor_Fase::criarEspaco()
    {
        Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Espaco());
        if (fase == nullptr) {
            std::cout << "Construtor::Construtor_Fase::nao foi possivel criar Fase Espaço" << std::endl;
            exit(1);
        }
        return fase;
    }*/
}