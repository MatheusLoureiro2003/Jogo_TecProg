#include "Jogo.h"

Gerenciadores::Gerenciador_Grafico* Jogo::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEve = Gerenciadores::Gerenciador_Eventos::getInstance();

Jogo::Jogo()
{
    //pGG = Gerenciador_Grafico::getInstance();
    fase1 = new Fases::Fase();
    LEs = fase1->getListaEntidades();
    Executar();
}

Jogo::~Jogo()
{
    pGG = nullptr;
}

void Jogo::Executar()
{
    while (pGG->isWindowOpen())
    {
        pEve->executar();
        /*sf::Event event;
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }*/

        pGG->clearWindow();
        LEs->executar();
        fase1->draw();
        pGG->displayWindow();
    }

}
