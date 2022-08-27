#include "Note.h"
using namespace std;

Note::Note(string message, Component *component) : AddOn(0, component)
{
    this->message = message;
}

Note::~Note()
{
    delete component;
}

bool Note::isDiscountable()
{
    return false;
}

double Note::getPrice()
{
    if (component->hasNote())
        return 0 + component->getPrice();
    else
        return AddOn::getPrice();
}

std::string Note::getDescription()
{
    if (component->hasNote())
        return "" + component->getDescription();
    else
        return "Note with message: " + message + "\n" + component->getDescription();
}

bool Note::hasNote()
{
    return true;
}

bool Note::hasCard()
{
    return component->hasCard();
}