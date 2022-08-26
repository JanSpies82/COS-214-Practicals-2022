#include "Basket.h"
using namespace std;

Basket::Basket() : Component()
{
    this->confectionaries = new vector<Confectionary *>();
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
    return "This is a basket with " + to_string(confectionaries->size()) + " confectionaries";
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
    return price;
}
