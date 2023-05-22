#include "Gerenciador_Grafico.h"


Gerenciador_Grafico* Gerenciador_Grafico::instance = nullptr;

Gerenciador_Grafico* Gerenciador_Grafico::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Gerenciador_Grafico();
	}
	return instance;
}

Gerenciador_Grafico::Gerenciador_Grafico() :window(new sf::RenderWindow(sf::VideoMode(400, 400), "juego", sf::Style::Titlebar | sf::Style::Close))
{}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	delete (window);
}
//retorna o caso de a janela estar aberta
bool Gerenciador_Grafico::isWindowOpen() const
{
	return window->isOpen();
}

void Gerenciador_Grafico::displayWindow()
{
	if (isWindowOpen())
		window->display();
}

void Gerenciador_Grafico::clearWindow()
{
	if (isWindowOpen())
		window->clear();
}

void Gerenciador_Grafico::closeWindow()
{
	window->close();
}

sf::RenderWindow* Gerenciador_Grafico::getWindow() const
{
	return window;
}



