#include "bot.hpp"
#include <vector>
#include <time.h>

Bot::Bot() : Object(Object::Type::Bot)
{
    mIndex = 0;
    srand(time(NULL));
    mDirection = rand() % 4;
    mHealth = 100;

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

void Bot::poison(int damage)
{
    mHealth -= 15;
    if(mHealth <= 0) 
    {

    }
}

void Bot::feed()
{
    mHealth = max(mHealth + 10, 90);
}

int getHealth()
{
    return mHealth;
}

Commands nextStep()
{
    Commands command;
    if(mIndex = mSteps.size()) mIndex = 0;
    switch(mSteps[mIndex])
    {
        case Bot::Commands::OneStep:
        {
            command = Bot::Commands::OneStep;
            return command;
        }
        case Bot::Commands::Grab:
        {
            command = Bot::Commands::OneStep;
            return command;
        }
        case Bot::Commands::Look:
        {
            command = Bot::Commands::Look;
            break;
        }
        case Bot::Commands::TurnRight:
        {
            mDirection++;
            mDirection %= 8;
            break;
        }
        case Bot::Commands::TurnLeft:
        {
            mDirection--;
            mDirection %= 8;
            break;
        }
        case Bot::Commands::Convert:
        {
            command = Bot::Commands::Convert;
            break;
        }
        case Bot::Commands::Unctrans:
        {
            command = Bot::Commands::Unctrans;
            break;
        }
    }
    mIndex++;
    return command;
}