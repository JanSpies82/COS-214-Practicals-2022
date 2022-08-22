#ifndef CONFECTIONARYFACTORY_H
#define CONFECTIONARYFACTORY_H
#include "Confectionary.h"
class ConfectionaryFactory
{

public:
	ConfectionaryFactory();
	~ConfectionaryFactory();
	virtual Confectionary *createChocolate(bool slab) = 0;
	virtual Confectionary *createAeratedChocolate(int bubblespccm) = 0;
};

#endif
