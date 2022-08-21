#ifndef LINDTFACTORY_H
#define LINDTFACTORY_H

#include "ConfectionaryFactory.h"
class LindtFactory : public ConfectionaryFactory
{
public:
	Confectionary *createChocolate();
	Confectionary *createAeratedChocolate();
};

#endif
