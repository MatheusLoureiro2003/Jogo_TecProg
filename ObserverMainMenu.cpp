#include "ObserverMainMenu.h"
#include "MainMenu.h"
#include "Gerenciador_Estados.h"

Observadores::ObserverMainMenu::ObserverMainMenu(Menus::MainMenu* menuPrincipal): Observadores::Observer(),menuPrincipal(menuPrincipal)
{
}

Observadores::ObserverMainMenu::~ObserverMainMenu()
{
}

void Observadores::ObserverMainMenu::IsKeyPressed(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::Enter):
    {
        switch (menuPrincipal->getIDBotaoSelecionado())
        {
        case (IDs::botao_novoJogo):
        {
            pGE->addState(IDs::jogar_cyberpunk);
        }
        break;
        case (IDs::botao_sair):
        {
            pGE->removeState();
        }
        break;
        }
    }
    break;
    }
}

void Observadores::ObserverMainMenu::IsKeyLoose(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::Up):
    {
        menuPrincipal->selectAbove();
    }
    break;
    case (sf::Keyboard::Down):
    {
        menuPrincipal->selectBelow();
    }
    break;
    }
}

void Observadores::ObserverMainMenu::moveMouse(const sf::Vector2f posMouse)
{
    menuPrincipal->eventMouse(posMouse);
}

void Observadores::ObserverMainMenu::buttonLooseMouse(const sf::Mouse::Button botaoMouse)
{
    if (menuPrincipal->getMouseSelected()) {
        switch (botaoMouse)
        {
        case (sf::Mouse::Left):
        {
            switch (menuPrincipal->getIDBotaoSelecionado())
            {
            case (IDs::botao_novoJogo):
            {
                pGE->addState(IDs::jogar_cyberpunk);
            }
            break;
            case (IDs::botao_sair):
            {
                pGE->removeState();
            }
            break;
            }
            break;
        }
        }
    }
}