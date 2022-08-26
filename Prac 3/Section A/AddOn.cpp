#include "AddOn.h"
using namespace std;

AddOn::AddOn(double price, Component *component) : Component()
{
    this->price = price;
    this->component = component;
    this->discount = 0;
}

AddOn::~AddOn()
{
}

Component *AddOn::getComponent()
{
    return component;
}

void AddOn::setComponent(Component *component)
{
    if (this->component != NULL)
    {
        delete this->component;
    }
    this->component = component;
}

bool AddOn::canAddDiscount()
{
    return true;
}

void AddOn::setDiscount(double discount)
{
    this->discount = discount;
    component->setDiscount(discount);
}

double AddOn::getPrice()
{
    if (isDiscountable())
        return price - (price * discount) + component->getPrice();
    else
        return price + component->getPrice();
}