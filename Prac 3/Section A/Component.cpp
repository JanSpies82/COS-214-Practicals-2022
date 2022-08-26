#include "Component.h"
using namespace std;
Component::Component()
{
    this->discount = 0;
}

Component::~Component()
{
}

double Component::getDiscount()
{
    return discount;
}

void Component::setDiscount(double discount)
{
    this->discount = discount;
}
