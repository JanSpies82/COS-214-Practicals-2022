#ifndef AERATEDcHOCOLATE_H
#define AERATEDcHOCOLATE_H
#include "Confectionary.h"

class AeratedChocolate : public Confectionary
{
public:
	AeratedChocolate(std::string manufacturer, double price, int bubblespccm);
	std::string getDescription();
	int getBubblespccm();

private:
	int bubblespccm;
};

#endif
