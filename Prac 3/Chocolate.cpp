#include "Chocolate.h"
using namespace std;

Chocolate::Chocolate(string manufacturer, double price, bool slab) : Confectionary(manufacturer, price, "Chocolate")
{
	this->slab = slab;
}

string Chocolate::getDescription()
{
	return "";
}
