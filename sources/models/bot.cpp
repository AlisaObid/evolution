#include "bot.hpp"
#include <vector>
#include <time.h>

Bot::Bot() : Object(Object::Type::Bot)
{
    mIndex = -1;
}

Bot::Commands Bot::createStep()
{
    srand(time(NULL));
    int num = rand() % 6;
    std::vector<Bot::Commands> commands =
    {
        Bot::Commands::OneStep,
        Bot::Commands::Grab,
        Bot::Commands::Look,
        Bot::Commands::TurnRight,
        Bot::Commands::TurnLeft,
        Bot::Commands::Convert, 
        Bot::Commands::Unctrans
    };
    return commands[num];
}

void Bot::setSteps()
{
    for (int i = 0; i < 60; i++)
    {
        mSteps.push_back(createStep());
    }
}

void Bot::dealDamage(int damage)
{
    mHealph -= damage;
}

int Bot::giveHealph()
{
    return mHealph;
}

Bot::Commands Bot::giveStep()
{
    if (mIndex == mSteps.size()) mIndex = -1;
    mIndex++;
    return mSteps[mIndex];
}