#ifndef BOT_HPP
#define BOT_HPP

#include <stdlib.h>
#include <time.h>
#include <vector>

#include "object.hpp"

class Bot : public Object
{
public:
    Bot();
     enum class Commands
    {
        OneStep,
        Grab,
        Look,
        TurnRight,
        TurnLeft,
        Convert, 
        Unctrans
    };   
    enum class Direction
    {
        Up,
        Right,
        Down,
        Left
    };
    int giveHealph();
    Bot::Commands nextStep();
    void dealDamage(int damage);

private:

    Commands createStep();
    void setSteps();
    std::vector<Commands> mSteps;
    int mIndex;
    int mHealth;
    int mDirection;
};

#endif // !BOT_HPP
