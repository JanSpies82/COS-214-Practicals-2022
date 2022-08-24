#include "Basket.h"
using namespace std;

Basket::Basket() : Confectionary("Lynwood Florest", 0, "Basket")
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

void Basket::add(Confectionary *confectionary)
{
    confectionaries->push_back(confectionary);
}

Confectionary *Basket::getConfectionary(int index)
{
    return confectionaries->at(index);
}

string Basket::getDescription()
{
    return "";
}

int Basket::getSize()
{
    return confectionaries->size();
}