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
    std::vector <std::vector<Object*>> mCells;
    int mCellSize, mScreenX, mScreenY;
    sf::RenderWindow& mWindow;
};

#endif // !WORLD_HPP
