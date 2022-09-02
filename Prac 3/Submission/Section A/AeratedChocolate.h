#ifndef AERATEDcHOCOLATE_H
#define AERATEDcHOCOLATE_H
#include "Confectionary.h"

class AeratedChocolate : public Confectionary
{
public:
	AeratedChocolate(std::string manufacturer, double price, int bubblespccm);
	virtual ~AeratedChocolate();
	std::string getDescription();
	int getBubblespccm();

protected:
	int bubblespccm;
};

#endif
