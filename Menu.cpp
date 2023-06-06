#include "Menu.h"

Menu::Menu(const IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte):
	Ente(ID), ButtonList(), it(), ButtonSize(tamBotao),WindowSize(pGG->getWindowSize()), BackPosition(sf::Vector2f(0.0f,0.0f)),
	MenuName(pGG->loadFont("Jogo_TecProg/Assets/ThaleahFat.ttf"), nome, tamFonte)
{
}

Menu::~Menu()
{
	if (!ButtonList.empty()) {
		for (it - ButtonList.begin(); it != ButtonList.end(); it++) {
			delete(*it);
			*it = nullptr;
		}
		ButtonList.clear();
	}
}

void Menu::addButton(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado)
{
}

void Menu::draw()
{
}

void Menu::selectAbove()
{
}

void Menu::selectBelow()
{
}

const IDs Menu::getIDBotaoSelecionado()
{
	return IDs();
}

void Menu::eventMouse(const sf::Vector2f posMouse)
{
}

const bool Menu::getMouseSelected() const
{
	return false;
}
