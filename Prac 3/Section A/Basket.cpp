#include "Basket.h"
#include "Confectionary.h"
using namespace std;

Basket::Basket() : Component()
{
    this->confectionaries = new vector<Confectionary *>();
    setType("Basket");
}

Basket::~Basket()
{
    for (vector<Confectionary *>::iterator it = confectionaries->begin(); it != confectionaries->end(); ++it)
    {
        delete *it;
    }
    delete confectionaries;
}

void Basket::add(Confectionary *c)
{
    confectionaries->push_back(c);
}

Confectionary *Basket::getConfectionary(int i)
{
    return confectionaries->at(i);
}

string Basket::getDescription()
{
    string out = "";
    out += "This is a basket with " + to_string(confectionaries->size()) + " confectionary(s):\n";
    for (vector<Confectionary *>::iterator it = confectionaries->begin(); it != confectionaries->end(); ++it)
    {
        out += (*it)->getDescription();
    }
    return out;
}

int Basket::getSize()
{
    return confectionaries->size();
}

double Basket::getPrice()
{
    double price = 0;
    for (vector<Confectionary *>::iterator it = confectionaries->begin(); it != confectionaries->end(); ++it)
    {
        price += (*it)->getPrice();
    }
    setPrice(price);
    return price;
}

string Basket::getType()
{
    return type;
}

void Basket::setPrice(double price)
{
    this->price = price;
}

void Basket::setType(string type)
{
    this->type = type;
}

bool Basket::canAddDiscount()
{
    return true;
}

bool Basket::isDiscountable()
{
    return false;
}

void Basket::setDiscount(double discount)
{
    this->discount = discount;
    for (vector<Confectionary *>::iterator it = confectionaries->begin(); it != confectionaries->end(); ++it)
    {
        (*it)->setDiscount(discount);
    }
}

bool Basket::hasNote()
{
    return false;
}

bool Basket::hasCard()
{
    return false;
}