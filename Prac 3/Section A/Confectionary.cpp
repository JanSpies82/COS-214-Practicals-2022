#include "Confectionary.h"
using namespace std;
int Confectionary::counter = 1;

Confectionary::Confectionary(string manufacturer, double price, string type) : Component(), manufacturer(manufacturer), price(price), type(type)
{
	id = counter++;
};

Confectionary::Confectionary() : Component(){};

Confectionary::~Confectionary()
{
}

string Confectionary::getDescription()
{
	string out = "";
	out += "Confectionary " + to_string(id) + ": " + manufacturer + " " + type + " costs R" + to_string(price).substr(0, to_string(price).find(".") + 3);
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
string Confectionary::getType()
{
    return type;
}

void Confectionary::setPrice(double price)
{
    this->price = price;
}

void Confectionary::setType(string type)
{
    this->type = type;
}