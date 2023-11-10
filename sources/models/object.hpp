#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include <map>
#include <vector>

class Object
{
public:
    enum class Type
    {
        None,
        Empty,
        Food,
        Poison,
        Bot,
        Wall
    };
    Object(Type aType);
    Type getType();

private:
    Type mType;
};

#endif // !OBJECT_HPP
