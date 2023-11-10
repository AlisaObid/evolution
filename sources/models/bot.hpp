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
    void giveHealth();
    void giveSteps();

private:
    enum class Type
    {
        OneStep,
        Grab,
        Look,
        Turn,
        Convert,
        Unctrans
    };
    pair<Type, int> createStep();
    Type setSteps();
    vector<Type> mSteps;
    int mHealth;
    int mOneStepMax, mGrabMax, mLookMax, mTurnMax, mUnctransMax;
};

#endif // !BOT_HPP
