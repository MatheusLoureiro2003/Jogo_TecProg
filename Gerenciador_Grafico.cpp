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

void Gerenciadores::Gerenciador_Grafico::setWindowSize(Matematica::CoordU size)
{
	window->setSize(sf::Vector2u(size.x, size.y));
	view.setSize(size.x, size.y);
	window->setView(view);
}

Matematica::CoordU Gerenciadores::Gerenciador_Grafico::getWindowSize() const
{
	return Matematica::CoordU(window->getSize().x, window->getSize().y);
}

Matematica::CoordF Gerenciadores::Gerenciador_Grafico::getTopLeftPosition() const
{
	return Matematica::CoordF(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
}

void Gerenciadores::Gerenciador_Grafico::centerView(Matematica::CoordF pos)
{
	view.setCenter(sf::Vector2f(pos.x, pos.y));
	window->setView(view);
}

sf::Texture* Gerenciadores::Gerenciador_Grafico::loadTexture(const char* path)
{
	/* Procura a textura e a liga � uma chave */
	std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
	while (it != texturesMap.end()) {
		if (!strcmp(it->first, path))
			return it->second;
		it++;
	}

	/* Se n�o achar a textura, carrega uma nova */
	sf::Texture* tex = new sf::Texture();

	if (!tex->loadFromFile(path)) {
		std::cout << "ERROR loading file " << path << std::endl;
		exit(1);
	}

	texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

	return tex;
}

sf::Font* Gerenciadores::Gerenciador_Grafico::loadFont(const char* path)
{
	/* Tenta achar a fonte existente e a liga � uma chave */
	std::map<const char*, sf::Font*>::iterator it = fontsMap.begin();
	while (it != fontsMap.end()) {
		if (!strcmp(it->first, path))
			return it->second;
		it++;
	}

	/* Se n�o achar textura, cria uma nova */
	sf::Font* font = new sf::Font();

	if (!font->loadFromFile(path)) {
		std::cout << "ERROR loading file " << path << std::endl;
		exit(1);
	}

	fontsMap.insert(std::pair<const char*, sf::Font*>(path, font));

	return font;
}



