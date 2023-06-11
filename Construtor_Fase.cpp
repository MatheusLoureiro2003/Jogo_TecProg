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
            fase = createCyberPunk();
        }
        break;
        case (IDs::jogar_deserto):
        {
            fase = createDeserto();
        }
        break;
        case (IDs::jogar_espaco):
        {
            fase = createSpace();
        }
        break;
        default:
        {
            std::cout << "Construtor::ConstrutorFase::ID da Fase invalido" << std::endl;
            exit(1);
        }
        break;
        }
        fase->createBackground();
        fase->createMap();
        return fase;
    }

    Fases::Fase* Construtor_Fase::createCyberPunk()
    {
        Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Cyberpunk());
        if (fase == nullptr) {
            std::cout << "Construtor::Construtor_Fase::nao foi possivel criar Fase cyberpunk" << std::endl;
            exit(1);
        }
        return fase;
    }

    Fases::Fase* Construtor_Fase::createDeserto()
    {
        Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Deserto());
        if (fase == nullptr) {
            std::cout << "Construtor::Construtor_Fase::nao foi possivel criar Fase deserto" << std::endl;
            exit(1);
        }
        return fase;
    }

    Fases::Fase* Construtor_Fase::createSpace()
    {
        Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Space());
        if (fase == nullptr) {
            std::cout << "Construtor::Construtor_Fase::nao foi possivel criar Fase Espaço" << std::endl;
            exit(1);
        }
        return fase;
    }
}