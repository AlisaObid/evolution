#include "world.hpp"
#include "models/object.hpp"
#include "models/bot.hpp"
#include <fstream>
#include <iostream>
#include <vector>

#define BOTS 0
#define FOOD 1
#define WALL 2
#define POISON 3
#define EMPTY 4

World::World(sf::RenderWindow& aWindow, int aCellSize)
    : mWindow(aWindow), mCellSize(aCellSize)
{
    mWindow.setVerticalSyncEnabled(true);
    mWindow.setFramerateLimit(60);

    mScreenX = 1000;
    mScreenY = 1000;

    std::ifstream fin("settings.txt");
    std::string str;

    std::vector<int> remCells(5);
    remCells[BOTS] = 10;
    remCells[FOOD] = 30;
    remCells[WALL] = 20;
    remCells[POISON] = 15;

    while(fin >> str)
    {
        if(str == "screen_extension")
        {
            fin >> mScreenX >> mScreenY;
        }
        if(str == "bots_count")
        {
            fin >> remCells[BOTS];
        }
        if(str == "poisonCount")
        {
            fin >> remCells[POISON];
        }
        if(str == "foodCount")
        {
            fin >> remCells[FOOD];
        }
        if(str == "wallCount")
        {
            fin >> remCells[WALL];
        }
    }

    mWindow.create(sf::VideoMode(mScreenX, mScreenY), "Ɐ");
    mWindow.setFramerateLimit(60);

    int maxCoorX, maxCoorY, xDist, yDist;
    maxCoorX = mScreenX - 2 * mCellSize;
    maxCoorY = mScreenY - 2 * mCellSize;
    xDist = mCellSize * 2 - 3;
    yDist = mCellSize * 2 - 7;
    mCells.resize((maxCoorY - 1) / yDist + 1, std::vector<Object*>((maxCoorX - 1) / xDist + 1, new Object(Object::Type::None)));
    remCells[EMPTY] = mCells.size() * mCells[0].size() - remCells[BOTS] - remCells[FOOD] - remCells[POISON] - remCells[WALL];
    newWorld(remCells);
}

void newWorld(std::vector<int> remCells)
{
    std::cout<< "Generation map..." << endl;
    for(int i = 0; i < mCells.size(); i++)
    {
        for(int j = 0; j < mCells[i].size(); j++)
        {
            if(i == 0 || i == mCells.size() - 1 || j == 0 || j == mCells[i].size() - 1)
            {
                mCells[i][j] = Object::Type::Wall;
                continue;
            }
            
            srand(time(NULL));
            int Cell = rand() % 5;
            while(remCell[Cell] == 0) Cell = rand() % 5;
            remCell[Cell]--;
            switch(Cell)
            {
                case BOTS: mCells[i][j] = Object::Type::Bot;
                case WALL: mCells[i][j] = Object::Type::Wall;
                case EMPTY: mCells[i][j] = Object::Type::Empty;
                case FOOD: mCells[i][j] = Object::Type::Food;
                case POISON: mCells[i][j] = Object::Type::Poison;
            }
        }
    }
    system("cls");
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
            switch(mCells[i][j]->getType())
            {
                case Object::Type::None:
                    color = sf::Color(255, 255, 255);
                case Object::Type::Empty:
                    color = sf::Color(33, 31, 54);
                case Object::Type::Food:
                    color = sf::Color(45, 194, 132);
                case Object::Type::Poison:
                    color = sf::Color(255, 41, 80);
                case Object::Type::Wall:
                    color = sf::Color(94, 143, 143);
                case Object::Type::Bot:
                    color = sf::Color(100, 76, 199);
            }
            square.setFillColor(color);
            mWindow.draw(square);
        }
        mWindow.display();
    }
}

void World::worldStep()
{
        std::vector<std::vector<Object*>> newCells = mCells;
        for (int i = 0; i < mCells.size(); i++)
        {
            for (int j = 0; j < mCells[i].size(); j++)
            {
                if (mCells[i][j]->getType() != Object::Type::Bot) continue;
                switch(((Bot*)mCells[i][j])->giveStep())
                {
                    case Bot::Commands::OneStep:
                    {
                        
                    }
                    case Bot::Commands::Grab:
                    {

                    }
                    case Bot::Commands::Look:
                    {

                    }
                    case Bot::Commands::Convert:
                    {

                    }
                    case Bot::Commands::Unctrans:
                    {

                    }
                    default:
                    {
                        continue;
                    }
                }
            }
        }
        mCells = newCells;
}
