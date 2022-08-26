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

std::string Note::getDescription()
{
    return "Note with message: " +  message + "\n" + component->getDescription();
}