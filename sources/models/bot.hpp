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
    void giveHealph();
    void giveStep();

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
    Type createStep();
    void setSteps();
    std::vector<Type> mSteps;
    static int index;
    int mHealph;
    int mOneStepMax, mGrabMax, mLookMax, mTurnMax, mConvertMax, mUnctransMax;
};

#endif // !BOT_HPP
