#ifndef NESTLEFACTORY_H
#define NESTLEFACTORY_H

#include "ConfectionaryFactory.h"
class NestleFactory : public ConfectionaryFactory
{
public:
	NestleFactory();
	~NestleFactory();
	Confectionary *createChocolate(bool slab);
	Confectionary *createAeratedChocolate(int bubblespccm);
};

#endif
