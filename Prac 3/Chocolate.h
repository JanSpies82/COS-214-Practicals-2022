#ifndef CHOCOLATE_H
#define CHOCOLATE_H
#include "Confectionary.h"
class Chocolate : public Confectionary
{
public:
	Chocolate(std::string manufacturer, double price, bool slab);
	std::string getDescription();
	bool getSlab();

private:
	bool slab;
};

#endif
