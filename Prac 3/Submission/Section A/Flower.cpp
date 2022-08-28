#include "Flower.h"
using namespace std;

Flower::Flower(string variety, Component *component) : AddOn(3.99, component)
{
    this->variety = variety;
}

Flower::~Flower()
{
    delete component;
}

bool Flower::isDiscountable()
{
    return true;
}

std::string Flower::getDescription()
{
    return "Flower of variety: " + variety + "\n" + component->getDescription();
}

bool Flower::hasNote()
{
    return component->hasNote();
}

bool Flower::hasCard()
{
    return component->hasCard();
}