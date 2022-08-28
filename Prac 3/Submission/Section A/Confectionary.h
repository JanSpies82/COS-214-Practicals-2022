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
	int getId();
	std::string getType();
    void setPrice(double price);
    void setType(std::string type);
	bool canAddDiscount();
	bool isDiscountable();
	void setDiscount(double discount);
	bool hasNote();
	bool hasCard();

protected:
	std::string manufacturer;
	int id;
	static int counter;
	double price;
    std::string type;
};

#endif
