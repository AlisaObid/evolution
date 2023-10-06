#include <SFML/Graphics.hpp>

#include "world.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), ".");
    window.setFramerateLimit(60);

    World world(20, window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        world.print();
        window.display();
    }
    
    return 0;
} // 28
