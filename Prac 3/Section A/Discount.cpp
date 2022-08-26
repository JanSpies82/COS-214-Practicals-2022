#include "Discount.h"
using namespace std;

Discount::Discount(std::string description, std::string date, double discount, Component *component) : Component()
{
    this->description = description;
    this->date = date;
    this->component = component;
    this->setDiscount(discount);
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
    return component->getPrice();
}

std::string Discount::getDate()
{
    return date;
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

bool Discount::canAddDiscount()
{
    return false;
}

bool Discount::isDiscountable()
{
    return false;
}

void Discount::setDiscount(double discount)
{
    this->discount = discount;
    component->setDiscount(discount);
}