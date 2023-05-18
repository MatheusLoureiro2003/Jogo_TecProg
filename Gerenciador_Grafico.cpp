#include "Gerenciador_Grafico.h"


#include <cstring>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

namespace Gerenciadores {

    /* Singleton design pattern - Only one instance will be created */
    Gerenciador_Grafico* Gerenciador_Grafico::instance = nullptr;

    /* Returns a pointer to the Graphics. */
    Gerenciador_Grafico* Gerenciador_Grafico::getInstance() {
        if (instance == nullptr) {
            instance = new Gerenciador_Grafico();
        }
        return instance;
    }

    Gerenciador_Grafico::Gerenciador_Grafico() :
        window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Desert", sf::Style::Titlebar | sf::Style::Close)),
        view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
        texturesMap(),
        fontsMap() { }

    Gerenciador_Grafico::~Gerenciador_Grafico() {
        std::map<const char*, sf::Texture*>::iterator it;

        for (it = texturesMap.begin(); it != texturesMap.end(); ++it) {
            delete (it->second);
        }

        delete (window);
    }

    void Gerenciador_Grafico::drawEnte(Ente* pE)
    {
    }

    /* Give a pointer to a body and it will be drawn to the screen. */
    void Gerenciador_Grafico::render(sf::RectangleShape* body) {
        window->draw(*body);
    }

    /* Give a pointer to a Text and it will be drawn to the screen */
    void Gerenciador_Grafico::render(sf::Text* text) {
        window->draw(*text);
    }

    /* Display everything that was drawn. */
    void Gerenciador_Grafico::display() {
        if (isWindowOpen())
            window->display();
    }

    /* Clear the window to re-display stuff. */
    void Gerenciador_Grafico::clear() {
        if (isWindowOpen())
            window->clear();
    }

    /* Returns if the window is open. */
    bool Gerenciador_Grafico::isWindowOpen() const {
        return window->isOpen();
    }

    /* CAUTION: Call the close window function - SFML window will close. */
    void Gerenciador_Grafico::closeWindow() {
        window->close();
    }

    /* Sets window size to its parameters */
    void Gerenciador_Grafico::setWindowSize(Matematica::CoordU size) {
        window->setSize(sf::Vector2u(size.x, size.y));
        view.setSize(size.x, size.y);
        window->setView(view);
    }

    /* Returns the window size. */
    Matematica::CoordU Gerenciador_Grafico::getWindowSize() const {
        return Matematica::CoordU(window->getSize().x, window->getSize().y);
    }

    /* Returns the top left position of screen. */
    Matematica::CoordF Gerenciador_Grafico::getTopLeftPosition() const {
        return Matematica::CoordF(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
    }

    /* Changes the view position. */
    void Gerenciador_Grafico::centerView(Matematica::CoordF pos) {
        view.setCenter(sf::Vector2f(pos.x, pos.y));
        window->setView(view);
    }

    /* Returns a texture to be used by an entity. */
    sf::Texture* Gerenciador_Grafico::loadTexture(const char* path) {
        /* Tries to find an existing texture linked by the path to it. */
        std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
        while (it != texturesMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }

    /* Returns a font pointer to be used by texts. */
    sf::Font* Gerenciador_Grafico::loadFont(const char* path) {
        /* Tries to find an existing font linked by the path to it */
        std::map<const char*, sf::Font*>::iterator it = fontsMap.begin();
        while (it != fontsMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        sf::Font* font = new sf::Font();

        if (!font->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        fontsMap.insert(std::pair<const char*, sf::Font*>(path, font));

        return font;
    }

    sf::RenderWindow* Gerenciador_Grafico::getWindow() const {
        return window;
    }

} // namespace Managers
