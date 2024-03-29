#ifndef LINDTFACTORY_H
#define LINDTFACTORY_H

#include "ConfectionaryFactory.h"
#include "Lindor.h"
class LindtFactory : public ConfectionaryFactory
{
public:
	LindtFactory();
	~LindtFactory();
	Confectionary *createChocolate(bool slab);
	Confectionary *createAeratedChocolate(int bubblespccm);
};

#endif
