#include "Jogo.h"

Gerenciadores::Gerenciador_Grafico* Jogo::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
Gerenciadores::Gerenciador_Estados* Jogo::pGE = Gerenciadores::Gerenciador_Estados::getInstance();

Jogo::Jogo()
{
    if (pGG == nullptr) {
        std::cout << "ERROR::Jogo nao foi possivel criar o Gerenciador_Grafico" << std::endl;
        exit(1);
    }
    if (pEve == nullptr) {
        std::cout << "ERROR::Jogo nao foi possivel criar um Gerenciador_Evento" << std::endl;
        exit(1);
    }
    if (pGE == nullptr) {
        std::cout << "ERROR::Jogo nao foi possivel criar um Gerenciador_Estado" << std::endl;
        exit(1);
    }
    inicializa();

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
        pGE->executar();
        LEs->executar();
        fase1->draw();
        pGG->displayWindow();
    }

}
void Jogo::inicializa() {
    pGE->addState(IDs::estado_menu_principal);
}
