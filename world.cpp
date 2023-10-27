#include "world.hpp"
#include "cell.hpp"
#include <fstream>
#include <iostream>
#include <vector>

World::World(sf::RenderWindow& aWindow, int aCellSize)
    : mWindow(aWindow), mCellSize(aCellSize)
{
    mScreenX = 1000;
    mScreenY = 1000;

    std::ifstream fin("settings.txt");
    std::string str;

    while(fin >> str)
    {
        if(str == "screen_extension")
        {
            fin >> mScreenX >> mScreenY;
        }
        
    }

    mWindow.create(sf::VideoMode(mScreenX, mScreenY), "_A_");
    mWindow.setFramerateLimit(60);

    int maxCoorX, maxCoorY, xDist, yDist;
    maxCoorX = mScreenX - 2 * mCellSize;
    maxCoorY = mScreenY - 2 * mCellSize;
    xDist = mCellSize * 2 - 3;
    yDist = mCellSize * 2 - 7;
    mCells.resize((maxCoorY - 1) / yDist + 1, std::vector<Cell>((maxCoorX - 1) / xDist + 1));
}

void World::print()
{
    sf::CircleShape square(mCellSize, 6);
    int maxCoorX, maxCoorY, xDist, yDist, indent;
    maxCoorX = mScreenX - 2 * mCellSize;
    maxCoorY = mScreenY - 2 * mCellSize;
    xDist   = mCellSize * 2 - 3;
    yDist   = mCellSize * 2 - 7;
    indent  = mCellSize - 2;
    mWindow.clear();
    for (int x = 0; x < maxCoorX; x += xDist)
    {
        for (int y = 0; y < maxCoorY; y += yDist)
        {
            square.setPosition((y % 2) * indent + x, y);
            sf::Color color(21, 26, 33);
            square.setFillColor(mCells[y / yDist][x / xDist].mColor);
            mWindow.draw(square);
        }
    }


    mWindow.display();
}
