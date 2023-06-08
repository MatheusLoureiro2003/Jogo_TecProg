#pragma once
#include "Cyberpunk.h"

namespace Construtor {
    class Construtor_Fase
    {
    private:
        Fases::Fase* createCyberPunk();
        Fases::Fase* criarDeserto();
        Fases::Fase* criarEspaco();
    public:
        Construtor_Fase();
        ~Construtor_Fase();
        Fases::Fase* createFase(const IDs ID);
    };
}
