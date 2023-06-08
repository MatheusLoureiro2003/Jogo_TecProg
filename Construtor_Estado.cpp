#include "Construtor_Estado.h"

Construtor_Estado::Construtor_Estado()
{
}

Construtor_Estado::~Construtor_Estado()
{
}

Estado* Construtor_Estado::createPlayState(const IDs ID)
{
    Fases::Fase* fase = nullptr;
    Construtor::Construtor_Fase construtorFase;

    fase = construtorFase.createFase(ID);

    EstadoPlay* estadoPlay = new EstadoPlay(ID, fase);
    return static_cast<Estado*>(estadoPlay);
}

Estado* Construtor_Estado::createMainMenu()
{
    Estado* estado = static_cast<Estado*>(new EstadoMainMenu());
    return estado;
}

Estado* Construtor_Estado::createMenuPause()
{
    Estado* estado = static_cast<Estado*>(new EstadoMenuPause());
    return estado;
}

Estado* Construtor_Estado::createState(const IDs ID)
{
    Estado* estado = nullptr;
    switch (ID)
    {
    case (IDs::jogar_cyberpunk):
    {
        estado = createPlayState(ID);
    }
    break;
    case (IDs::jogar_deserto):
    {
        estado = createPlayState(ID);
    }
    break;
    case (IDs::jogar_espaco):
    {
        estado = createPlayState(ID);
    }
    break;
    case (IDs::estado_menu_principal):
    {
        estado = createMainMenu();
    }
    break;
    case (IDs::estado_menu_pausa):
    {
        estado = createMenuPause();
    }
    break;
    }
    return estado;
}


