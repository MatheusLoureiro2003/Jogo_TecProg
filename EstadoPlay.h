#pragma once
#include "Estado.h"
#include "Gerenciador_Grafico.h"
#include "Construtor_Estado.h"
#include "Fase.h"

class EstadoPlay :
    public Estado
{
private:
    Fases::Fase* fase;
public:
    EstadoPlay(const IDs ID, Fases::Fase* fase);
    ~EstadoPlay();
    Fases::Fase* getFase();
    void executar();
   // void mudarEstadoObservador();
};

