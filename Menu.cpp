#include "Menu.h"

void Menu::UpdateBackPosition()
{
}

Menu::Menu(const IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte):
	Ente(ID), ButtonList(), it(), ButtonSize(tamBotao),WindowSize(pGG->getWindowSize()), BackPosition(sf::Vector2f(0.0f,0.0f)),
	MenuName(pGG->loadFont("Jogo_TecProg/Assets/ThaleahFat.ttf"), nome, tamFonte)
{
}

Menu::~Menu()
{
	if (!ButtonList.empty()) {
		for (it = ButtonList.begin(); it != ButtonList.end(); it++) {
			delete(*it);
			*it = nullptr;
		}
		ButtonList.clear();
	}
}

void Menu::addButton(const std::string info, const sf::Vector2f pos, const IDs ID, const sf::Color corSelecionado)
{
	Botao* button = new Botao(info, ButtonSize, pos, ID, corSelecionado);
	if (button == nullptr) {
		throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
	}
	ButtonList.push_back(button);
}

void Menu::draw()
{
	// desenha botôes na janela
	std::list<Botao*>::iterator aux;
	for (aux = ButtonList.begin(); aux != ButtonList.end(); aux++) {
		Botao* button = *aux;
		button->draw();
		button = nullptr;
	}
}



void Menu::selectBelow()
{
	Botao* button = *it;
	button->setSelecionado(false);
	it++;
	if (it == ButtonList.end()) {
		it = ButtonList.begin();
	}
	button = *it;
	button->setSelecionado(true);
}

void Menu::selectAbove()
{
	Botao* button = *it;
	button->setSelecionado(false);
	if (it == ButtonList.begin()) {
		it = ButtonList.end();
	}
	it--;
	button = *it;
	button->setSelecionado(true);
}

const IDs Menu::getIDBotaoSelecionado()
{
	return (*it)->getID();
}

void Menu::eventMouse(const sf::Vector2f posMouse)
{
	std::list<Botao*>::iterator aux;
	MouseSelected = false;
	for (aux = ButtonList.begin(); aux != ButtonList.end(); aux++) {
		Botao* button = *aux;
		sf::Vector2f posBotao = button->getPos();
		sf::Vector2f posCamera = pGG->getCamera().getCenter();
		if (posMouse.x + posCamera.x - WindowSize.x / 2.0f > posBotao.x && posMouse.x + posCamera.x - WindowSize.x / 2.0f < posBotao.x + ButtonSize.x &&
			posMouse.y + posCamera.y - WindowSize.y / 2.0f > posBotao.y && posMouse.y + posCamera.y - WindowSize.y / 2.0f < posBotao.y + ButtonSize.y) {
			(*it)->setSelecionado(false);
			it = aux;
			(*it)->setSelecionado(true);
			MouseSelected = true;
			break;
		}
	}
}

const bool Menu::getMouseSelected() const
{
	return MouseSelected;
}
