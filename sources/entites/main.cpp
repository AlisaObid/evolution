#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "models/bot.hpp"

#include "world.hpp"
int
main()
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

    // Bot b;
    // b.foo();
    // b.gaf();

    // Object o(Object::Type::Empty);
    // o.foo();

    // std::vector<Object*> a(2);
    // a[0] = new Object(Object::Type::Empty);
    // a[1] = new Bot;

    // // a[0]->foo();
    // // a[1]->foo();
    // for (auto ptr : a)
    // {
    //     ptr->foo2();
    //     if (ptr->getType() == Object::Type::Bot)
    //     {
    //         ((Bot*)ptr)->gaf();
    //     }
    //     std::cout << "============\n";
    // }

    return 0;
}
