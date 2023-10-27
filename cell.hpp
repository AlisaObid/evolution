#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

#include <map>
#include <vector>

class Cell
{
public:
    enum class Type
    {
        Nun,
        Empty,
        Food,
        Poison,
        Bot
    };


private:
    Type mType;

private:
};

#endif // !CELL_HPP
