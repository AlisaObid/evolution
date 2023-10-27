#include <SFML/Graphics.hpp>

#include <vector>
#include "world.hpp"

int main()
{
    sf::RenderWindow window;

    std::vector<std::vector<int>> a;
    a.resize(6, std::vector<int>(8));
    World world(window, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        world.print();
    }
    
    return 0;
}