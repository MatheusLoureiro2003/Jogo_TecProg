#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico
{
private:

	static Gerenciador_Grafico* instance;
	sf::RenderWindow* window;
	//sf::View view;
	Gerenciador_Grafico();

public:
	static Gerenciador_Grafico* getInstance();

	~Gerenciador_Grafico();

	bool isWindowOpen() const;

	void displayWindow();
	void clearWindow();

	void closeWindow();

	sf::RenderWindow* getWindow() const;

	void draw(sf::RectangleShape body) { window->draw(body); }

	float updateDeltaTime();
};

