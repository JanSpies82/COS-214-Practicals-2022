#include "Chocolate.h"
using namespace std;

Chocolate::Chocolate(string manufacturer, double price, bool slab) : Confectionary(manufacturer, price, "Chocolate")
{
	this->slab = slab;
}

bool Chocolate::getSlab()
{
	return slab;
};

string Chocolate::getDescription()
{
	string out = Confectionary::getDescription();
	if (slab)
		out += " is a slab";
	else
		out += " is a minibar";
	return out;
}
