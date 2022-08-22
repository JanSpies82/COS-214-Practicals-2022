#include "Confectionary.h"
using namespace std;
int Confectionary::counter = 1;

Confectionary::Confectionary(string manufacturer, double price, string type) : manufacturer(manufacturer), price(price), type(type)
{
	id = counter++;
};

string Confectionary::getDescription()
{
	string out = "";
	out += "Confectionary " + to_string(id) + ": " + manufacturer + " " + type + " costs " + to_string(price);
	return out;
}
double Confectionary::getPrice()
{
	return price;
};
std::string Confectionary::getManufacturer()
{
	return manufacturer;
};
std::string Confectionary::getType()
{
	return type;
};
int Confectionary::getId()
{
	return id;
};