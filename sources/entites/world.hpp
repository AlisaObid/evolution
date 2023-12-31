#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

#include "models/object.hpp"

class World
{
public:
    World(sf::RenderWindow& aWindow, int aCellSize);

    void print();

private:
    void worldStep();
    std::vector<std::vector<Object*>> mCells;
    int mCellSize, mScreenX, mScreenY, mBotsCount;
    sf::RenderWindow& mWindow;
};

#endif // !WORLD_HPP
