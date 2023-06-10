#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(60);

    sf::Font font;
    try
    {
        if (!font.loadFromFile("C:/Users/Matha/source/repos/jogo/Jogo_TecProg/Assets/ThaleahFat.ttf"))
        {
            throw std::runtime_error("COULD NOT LOAD FONT!");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setStyle(sf::Text::Bold);
    text.setString("OLA eu TO AQui");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
