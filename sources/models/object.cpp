#include "Object.hpp"

#include <iostream>
Object::Object(Type aType)
{
    mType = aType;
}

Object::Type
Object::getType()
{
    return mType;
}
