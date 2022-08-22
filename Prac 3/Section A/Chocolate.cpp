#include "Chocolate.h"
using namespace std;

Chocolate::Chocolate(string manufacturer, double price, bool slab) : Confectionary(manufacturer, price, "Bar")
{
	this->slab = slab;
}

Chocolate::~Chocolate()
{
}

bool Chocolate::getSlab()
{
	return slab;
};

string Chocolate::getDescription()
{
	string out = Confectionary::getDescription();
	if (slab)
		out += " and is a slab";
	else
		out += " and is a minibar";
	return out;
}
