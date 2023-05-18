#pragma once

#include "CoordenadaTL.h"
#include "Ente.h"
#include <SFML/Graphics.hpp>
#include <map>
namespace Gerenciadores {
    class Gerenciador_Grafico
    {
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const char*, sf::Texture*> texturesMap;
        std::map<const char*, sf::Font*> fontsMap;

        /* Singleton design pattern */
        static Gerenciadores::Gerenciador_Grafico* instance;
        Gerenciador_Grafico();

    public:
        ~Gerenciador_Grafico();

        void drawEnte(Ente* pE);

        static Gerenciador_Grafico* getInstance();

        void render(sf::RectangleShape* body);

        void render(sf::Text* text);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        void setWindowSize(Matematica::CoordU size);

        Matematica::CoordU getWindowSize() const;

        Matematica::CoordF getTopLeftPosition() const;

        void centerView(Matematica::CoordF pos);

        sf::Texture* loadTexture(const char* path);

        sf::Font* loadFont(const char* path);

        float updateDeltaTime();

        sf::RenderWindow* getWindow() const;

    };

} // namespace Gerenciadores

