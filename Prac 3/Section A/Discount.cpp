#include "Discount.h"
using namespace std;

Discount::Discount(std::string description, std::string date, double discount, Component *component)
{
    this->description = description;
    this->date = date;
    this->discount = discount;
    this->component = component;
}

Discount::~Discount()
{
    delete component;
}

std::string Discount::getDescription()
{
    return description;
}

double Discount::getPrice()
{
    return discount * component->getPrice();
}

std::string Discount::getDate()
{
    return date;
}

double Discount::getDiscount()
{
    return discount;
}

Component *Discount::getComponent()
{
    return component;
}

void Discount::setComponent(Component *component)
{
    if (this->component != NULL)
    {
        delete this->component;
    }
    this->component = component;
}