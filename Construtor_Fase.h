#pragma once
#include "Cyberpunk.h"
#include "Deserto.h"]
#include "Space.h"

namespace Construtor {
    class Construtor_Fase
    {
    private:
        Fases::Fase* createCyberPunk();
        Fases::Fase* createDeserto();
        Fases::Fase* createSpace();
    public:
        Construtor_Fase();
        ~Construtor_Fase();
        Fases::Fase* createFase(const IDs ID);
    };
}
