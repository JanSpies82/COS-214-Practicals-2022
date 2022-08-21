#ifndef AERO_H
#define AERO_H

#include "AeratedChocolate.h"
class Aero : public AeratedChocolate
{
public:
	Aero(std::string manufacturer, double price, int bubblespccm);
};

#endif
