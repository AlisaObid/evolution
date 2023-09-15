#include <SFML/Graphics.hpp>

#include <cmath>

#define PI 3.14159265

int
main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "A");
    window.setFramerateLimit(60);
    sf::CircleShape map;
    int mapSides  = 6, mapSideSize = 250;
    float mapSize = 100.f;
    map.setPointCount(mapSides);
    map.setFillColor(sf::Color::White);
    map.setOutlineThickness(100);
    sf::CircleShape square(600, 6);
    map.setPosition(450, 450);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        window.draw(square);
        window.display();
        }

    return 0;
}
