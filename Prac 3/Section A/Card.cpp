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

std::string Card::getDescription()
{
    return "Card with message: " + message;
}