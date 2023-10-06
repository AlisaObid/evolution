#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

class World
{
public:
    World(sf::RenderWindow& aWindow);

    void print();

private:
    int mSize;
    sf::RenderWindow& mWindow;
    std::vector<std::vector<int>> mPole;
};

#endif // !WORLD_HPP
