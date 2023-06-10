#pragma once
#include <SFML/Graphics.hpp>
#define TELA_X 800.0f
#define TELA_Y 600.0f

namespace Gerenciadores {
	class Gerenciador_Grafico
	{
	private:

		static Gerenciador_Grafico* instance;
		sf::RenderWindow* window;
		sf::View camera;
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

		void draw(sf::Text text) { window->draw(text); }

		const sf::View getCamera();
		
		const sf::Vector2f getWindowSize() const;

		void centerView(const sf::Vector2f pos);

		sf::Texture loadTexture(const char* path);

		sf::Font loadFont(const char* path);

		void resetWindow();
	};
}

