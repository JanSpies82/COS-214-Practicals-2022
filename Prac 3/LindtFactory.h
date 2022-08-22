#ifndef LINDTFACTORY_H
#define LINDTFACTORY_H

#include "ConfectionaryFactory.h"
class LindtFactory : public ConfectionaryFactory
{
public:
	LindtFactory();
	~LindtFactory();
	Confectionary *createChocolate();
	Confectionary *createAeratedChocolate();
};

#endif
