#include "Ribbon.h"
using namespace std;

Ribbon::Ribbon(string color, Component *component) : AddOn(7.75, component)
{
    this->color = color;
}

Ribbon::~Ribbon()
{
    delete component;
}

bool Ribbon::isDiscountable()
{
    return false;
}

std::string Ribbon::getDescription()
{
    return color + " colored ribbon\n" + component->getDescription();
}

bool Ribbon::hasNote()
{
    return component->hasNote();
}

bool Ribbon::hasCard()
{
    return component->hasCard();
}