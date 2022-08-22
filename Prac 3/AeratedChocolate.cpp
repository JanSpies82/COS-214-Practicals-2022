#include "AeratedChocolate.h"
using namespace std;

AeratedChocolate::AeratedChocolate(string manufacturer, double price, int bubblespccm) : Confectionary(manufacturer, price, "Aerated")
{
	this->bubblespccm = bubblespccm;
}

int AeratedChocolate::getBubblespccm()
{
	return bubblespccm;
};

string AeratedChocolate::getDescription()
{
	string out = Confectionary::getDescription();
	out += " with " + to_string(bubblespccm) + " bubbles per cubic cm";
	return out;
}
