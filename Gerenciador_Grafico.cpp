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

const sf::Vector2f Gerenciadores::Gerenciador_Grafico::getWindowSize() const
{
	return (sf::Vector2f)window->getSize();
}


void Gerenciadores::Gerenciador_Grafico::centerView(const sf::Vector2f pos)
{
	view.setCenter(pos);
	window->setView(view);
}

sf::Texture* Gerenciadores::Gerenciador_Grafico::loadTexture(const char* path)
{
	/* Procura a textura e a liga à uma chave */
	std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
	while (it != texturesMap.end()) {
		if (!strcmp(it->first, path))
			return it->second;
		it++;
	}

	/* Se não achar a textura, carrega uma nova */
	sf::Texture* tex = new sf::Texture();

	if (!tex->loadFromFile(path)) {
		std::cout << "ERROR loading file " << path << std::endl;
		exit(1);
	}

	texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

	return tex;
}

sf::Font Gerenciadores::Gerenciador_Grafico::loadFont(const char* path)
{
	sf::Font fonte;
	if (!fonte.loadFromFile(path)) {
		throw("ERROR::Jungle::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da fonte");
	}
	return fonte;
}





