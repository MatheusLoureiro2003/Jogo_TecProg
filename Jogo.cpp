#include "Jogo.h"

Gerenciadores::Gerenciador_Grafico* Jogo::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEve = Gerenciadores::Gerenciador_Eventos::getInstance();


Jogo::Jogo():mainMenu()
{
    if (pGG == nullptr) {
        std::cout << "ERROR::Jogo nao foi possivel criar o Gerenciador_Grafico" << std::endl;
        exit(1);
    }
    if (pEve == nullptr) {
        std::cout << "ERROR::Jogo nao foi possivel criar um Gerenciador_Evento" << std::endl;
        exit(1);
    }

    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (pGG->isWindowOpen())
    {
        pEve->executar();
        pGG->clearWindow();
        mainMenu.executar();
  
        pGG->displayWindow();
    }

}

