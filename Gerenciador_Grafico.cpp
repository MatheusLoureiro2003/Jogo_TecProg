#include "Gerenciador_Grafico.h"

#include <cstring>
#include <iostream>


Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instance = nullptr;

Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Gerenciador_Grafico();
	}
	return instance;
}

Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico() :window(new sf::RenderWindow(sf::VideoMode(1280, 720), "juego", sf::Style::Titlebar | sf::Style::Close))
{}

Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico()
{
	delete (window);
}
//retorna o caso de a janela estar aberta
bool Gerenciadores::Gerenciador_Grafico::isWindowOpen() const
{
	return window->isOpen();
}

void Gerenciadores::Gerenciador_Grafico::displayWindow()
{
	if (isWindowOpen())
		window->display();
}

void Gerenciadores::Gerenciador_Grafico::clearWindow()
{
	if (isWindowOpen())
		window->clear();
}

void Gerenciadores::Gerenciador_Grafico::closeWindow()
{
	window->close();
}

sf::RenderWindow* Gerenciadores::Gerenciador_Grafico::getWindow() const
{
	return window;
}

const sf::View Gerenciadores::Gerenciador_Grafico::getCamera()
{
	return camera;
}

const sf::Vector2f Gerenciadores::Gerenciador_Grafico::getWindowSize() const
{
	return (sf::Vector2f)window->getSize();
}


void Gerenciadores::Gerenciador_Grafico::centerView(const sf::Vector2f pos)
{
	camera.setCenter(pos);
	window->setView(camera);
}

sf::Texture Gerenciadores::Gerenciador_Grafico::loadTexture(const char* path)
{
	sf::Texture textura;
	if (!textura.loadFromFile(path)) {
		std::cout << "ERRO::Gerenciador::Gerenciador_Grafico::nao foi possivel encontrar o caminho da textura - " << path << std::endl;
		exit(1);
	}
	return textura;
	}
}

sf::Font Gerenciadores::Gerenciador_Grafico::loadFont(const char* path)
{
	sf::Font fonte;
	if (!fonte.loadFromFile(path)) {
		throw("ERROR::Gerenciador::Gerenciador_Grafico::nao foi possivel encontrar o caminho da fonte");
	}
	return fonte;
}

void Gerenciadores::Gerenciador_Grafico::resetWindow()
{
	camera.setCenter(TELA_X / 2.0f, TELA_Y / 2.0f);
	window->setView(camera);
}






