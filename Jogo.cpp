#include "Jogo.h"

Gerenciadores::Gerenciador_Grafico* Jogo::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

Jogo::Jogo()
{
    //pGG = Gerenciador_Grafico::getInstance();
    jogador1 = new Entidades::Personagens::Jogador();
    fase1 = new Fases::Fase1(jogador1);
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
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }
        pGG->clearWindow();
        jogador1->move();
        fase1->draw();
        pGG->displayWindow();
    }

}
