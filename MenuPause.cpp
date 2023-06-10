#include "MenuPause.h"
#include "ObserverMenuPause.h"

namespace Menus {
    MenuPause::MenuPause(Fases::Fase* fase) :
        Menu(IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "PAUSA", 100), fase(fase),
        darkBackground(WindowSize),
        painelBackground(sf::Vector2f(WindowSize.x / 2.0f, WindowSize.y)), observadorMenuPausa(new Observadores::ObserverMenuPause(this))
    {
        MenuName.setColorText(sf::Color{255, 0, 0});
        darkBackground.setFillColor(sf::Color{0, 0, 0, 180});
        painelBackground.setFillColor(sf::Color{0, 0, 0, 220});
        createButtons();
    }

    MenuPause::~MenuPause()
    {
        if (observadorMenuPausa) {
            delete(observadorMenuPausa);
            observadorMenuPausa = nullptr;
        }
    }

    void MenuPause::createButtons()
    {
        addButton("Voltar", sf::Vector2f(0.0f, 0.0f), IDs::botao_voltar, sf::Color{255, 0, 0});
        addButton("Salvar Jogada", sf::Vector2f(0.0f, 0.0f), IDs::botao_salvarJogada, sf::Color{255, 0, 0});
        addButton("Opcao", sf::Vector2f(0.0f, 0.0f), IDs::botao_opcao, sf::Color{255, 0, 0});
        addButton("Sair", sf::Vector2f(0.0f, 0.0f), IDs::botao_sair, sf::Color{255, 0, 0});
        it = ButtonList.begin();
        (*it)->setSelecionado(true);
    }

    void MenuPause::updateBackground()
    {
        UpdateBackPosition();
        sf::Vector2f posFundoEscuro = sf::Vector2f(BackPosition.x - WindowSize.x / 2.0f, BackPosition.y - WindowSize.y / 2.0f);
        darkBackground.setPosition(posFundoEscuro);
        painelBackground.setPosition(sf::Vector2f(posFundoEscuro.x + WindowSize.x / 4.0f, posFundoEscuro.y));

        pGG->draw(darkBackground);
        pGG->draw(painelBackground);
    }

    void MenuPause::updateMenuName()
    {
        MenuName.setPos(sf::Vector2f(BackPosition.x - MenuName.getTam().x / 2.1f, BackPosition.y - WindowSize.y / 2.0f));

        pGG->draw(MenuName.getText());
    }

    void MenuPause::updateButtons()
    {
        std::list<Botao*>::iterator aux;
        int i = 1;
        for (aux = ButtonList.begin(); aux != ButtonList.end(); aux++, i++) {
            Botao* botao = *aux;
            botao->updatePosition(sf::Vector2f(BackPosition.x - WindowSize.x / 4.6f, BackPosition.y / 1.5f + (ButtonSize.y + 20.f) * i));
            botao = nullptr;
        }

        draw();
    }

    void MenuPause::setFase(Fases::Fase* fase) {
        this->fase = fase;
    }

    void MenuPause::changeObserveState()
    {
        observadorMenuPausa->changeStateActivate();
    }

    void MenuPause::executar()
    {
        //somente pinta as entidades
        fase->draw();

        //atualiza o menu pausar
        updateBackground();
        updateMenuName();
        updateButtons();
    }
}


