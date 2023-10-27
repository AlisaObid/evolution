#include "world.hpp"
#include "models/object.hpp"
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

    mWindow.create(sf::VideoMode(mScreenX, mScreenY), "ⱯⱯⱯⱯⱯ");
    mWindow.setFramerateLimit(60);

    int maxCoorX, maxCoorY, xDist, yDist;
    maxCoorX = mScreenX - 2 * mCellSize;
    maxCoorY = mScreenY - 2 * mCellSize;
    xDist = mCellSize * 2 - 3;
    yDist = mCellSize * 2 - 7;
    mCells.resize((maxCoorY - 1) / yDist + 1, std::vector<Object*>((maxCoorX - 1) / xDist + 1, new Object(Object::Type::None)));
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
            int i = y / yDist, j = x / xDist;
            square.setPosition((y % 2) * indent + x, y);
            sf::Color color;
            switch( Object::Type::*mCells[i][j].getType() )
            {
                case Object::Type::None:
                    color = new sf::Color(255, 255, 255);
                case Object::Type::Empty:
                    color = new sf::Color(33, 31, 54);
                case Object::Type::Food:
                    color = new sf::Color(45, 194, 132);
                case Object::Type::Poison:
                    color = new sf::Color(255, 41, 80);
                case Object::Type::Bot:
                    color = new sf::Color(247, 160, 109);
            }
            square.setFillColor(color);
            mWindow.draw(square);
        }
    }


    mWindow.display();
}
