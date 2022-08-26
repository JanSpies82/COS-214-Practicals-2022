#ifndef CONFECTIONARY_H
#define CONFECTIONARY_H
#include "Component.h"
class Confectionary: public Component
{
public:
	Confectionary(std::string manufacturer, double price, std::string type);
	Confectionary();
	virtual ~Confectionary();
	virtual std::string getDescription();
	double getPrice();
	std::string getManufacturer();
	std::string getType();
	int getId();
	std::string getType();
    void setPrice(double price);
    void setType(std::string type);

protected:
	std::string manufacturer;
	int id;
	static int counter;
	double price;
    std::string type;
};

#endif
