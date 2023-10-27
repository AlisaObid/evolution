#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

#include "cell.hpp"

class World
{
public:
    World(sf::RenderWindow& aWindow, int aCellSize);

    void print();

private:
    std::vector <std::vector<Cell>> mCells;
    int mCellSize, mScreenX, mScreenY;
    sf::RenderWindow& mWindow;
    std::vector<std::vector<int>> mMap;
};

#endif // !WORLD_HPP
