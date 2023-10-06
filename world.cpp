#include "world.hpp"

#include <fstream>
#include <iostream>

World::World(sf::RenderWindow& aWindow)
    : mSize(aSize), mWindow(aWindow)
{
    std::ifstream fin("settings.txt");
    //if (file.is_open())std::cout << "YES!";
    map<string, int> settings;
    
    while(fin >> str >> num)
    {

    }

}

void
World::print()
{
    sf::CircleShape square(mSize, 6);
    int maxCoor, xDist, yDist, indent;
    maxCoor = 1000 - 2 * mSize;
    xDist   = mSize * 2 - 3;
    yDist   = mSize * 2 - 7;
    indent  = mSize - 2;
    for (int x = 0; x < maxCoor; x += xDist)
    {
        for (int y = 0; y < maxCoor; y += yDist)
        {
            square.setPosition((y % 2) * indent + x, y);
            mWindow.draw(square);
        }
    }
}
