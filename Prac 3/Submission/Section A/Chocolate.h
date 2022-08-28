#ifndef CHOCOLATE_H
#define CHOCOLATE_H
#include "Confectionary.h"
class Chocolate : public Confectionary
{
public:
	Chocolate(std::string manufacturer, double price, bool slab);
	virtual ~Chocolate();
	std::string getDescription();
	bool getSlab();

protected:
	bool slab;
};

#endif
