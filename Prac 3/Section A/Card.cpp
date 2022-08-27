#include "Card.h"
using namespace std;

Card::Card(string message, Component *component) : AddOn(25.9, component)
{
    this->message = message;
}

Card::~Card()
{
    delete component;
}

bool Card::isDiscountable()
{
    return true;
}

double Card::getPrice()
{
    if (component->hasCard())
        return 0 + component->getPrice();
    else
        return AddOn::getPrice();
}

std::string Card::getDescription()
{
    if (component->hasCard())
        return "" + component->getDescription();
    else
        return "Card with message: " + message + "\n" + component->getDescription();
}

bool Card::hasNote()
{
    return component->hasNote();
}

bool Card::hasCard()
{
    return true;
}