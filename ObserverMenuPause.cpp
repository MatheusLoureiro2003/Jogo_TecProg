#include "ObserverMenuPause.h"

Observadores::ObserverMenuPause::ObserverMenuPause(Menu::MenuPause* menuPausa):
	menuPausa(menuPausa)
{
}

Observadores::ObserverMenuPause::~ObserverMenuPause()
{
}

void Observadores::ObserverMenuPause::isKeyPressed(const sf::Keyboard::Key tecla)
{
    switch(tecla)
    {
                case (sf::Keyboard::Enter):
                {
                    switch (menuPausa->getIDBotaoSelecionado())
                    {
                    case (IDs::botao_voltar):
                    {
                        pGE->removerEstado();
                    }
                    break;
                    case (IDs::botao_sair):
                    {
                        pGE->removeState();
                        pGE->removeState();
                    }
                    break;
                    }
                }
                break;
    }
}

void Observadores::ObserverMenuPause::isKeyLoose(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::Up):
    {
        menuPausa->selectAbove();
    }
    break;
    case (sf::Keyboard::Down):
    {
        menuPausa->selectBelow();
    }
    break;
    }
}

void Observadores::ObserverMenuPause::moveMouse(const sf::Vector2f posMouse)
{
    menuPausa->eventMouse(posMouse);
}

void Observadores::ObserverMenuPause::buttonLooseMouse(const sf::Mouse::Button botaoMouse)
{
    if (menuPausa->getMouseSelected()) {
        switch (botaoMouse)
        {
        case (sf::Mouse::Left):
        {
            switch (menuPausa->getIDBotaoSelecionado())
            {
            case (IDs::botao_voltar):
            {
                pGE->removeState();
            }
            break;
            case (IDs::botao_sair):
            {
                pGE->removeState();
                pGE->removeState();
            }
            break;
            }
        }
        break;
        }
    }
}
