#ifndef CONFECTIONARYFACTORY_H
#define CONFECTIONARYFACTORY_H
#include "Confectionary.h"
class ConfectionaryFactory
{

public:
	ConfectionaryFactory();
	~ConfectionaryFactory();
	virtual Confectionary *createChocolate() = 0;
	virtual Confectionary *createAeratedChocolate() = 0;
};

#endif
