#include "bot.hpp"

Bot::Bot() : Object(Object::Type::Bot)
{
}

Bot::Type Bot::setSteps()
{
    for (int i = 0; i < 10; i++)
    {
        mSteps = createStep()
    } 
}

pair<Bot::Type, int> Bot::createStep()
{
    int num = 1 + (rand() % 6);
    switch(num)
    {
        case 1 :
            return Bot::Type::OneStep;
        case 2 :
            return Bot::Type::Grab;
        case 3 :
            return Bot::Type::Look;
        case 4 :
            return Bot::Type::Turn;
        case 5 :
            return Bot::Type::Convert;
        case 6 :
            return Bot::Type::Unctrans;
    }
}