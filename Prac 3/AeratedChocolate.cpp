#include "AeratedChocolate.h"
using namespace std;

AeratedChocolate::AeratedChocolate(string manufacturer, double price, int bubblespccm) : Confectionary(manufacturer, price, "Aerated Chocolate")
{
	this->bubblespccm = bubblespccm;
}

string AeratedChocolate::getDescription()
{
	return "";
}
