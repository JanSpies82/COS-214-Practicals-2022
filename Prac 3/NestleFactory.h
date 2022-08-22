#ifndef NESTLEFACTORY_H
#define NESTLEFACTORY_H

#include "ConfectionaryFactory.h"
class NestleFactory : public ConfectionaryFactory
{
public:
	NestleFactory();
	~NestleFactory();
	Confectionary *createChocolate();
	Confectionary *createAeratedChocolate();
};

#endif
