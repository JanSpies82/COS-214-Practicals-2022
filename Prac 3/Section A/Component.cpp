#include "Component.h"
using namespace std;

Component::Component(double price, string type) : price(price), type(type)
{
}

Component::Component()
{
}

Component::~Component()
{
}

string Component::getType()
{
    return type;
}

void Component::setPrice(double price)
{
    this->price = price;
}

void Component::setType(string type)
{
    this->type = type;
}