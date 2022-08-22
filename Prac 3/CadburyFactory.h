#ifndef CADBURYFACTORY_H
#define CADBURYFACTORY_H

#include "ConfectionaryFactory.h"
class CadburyFactory : public ConfectionaryFactory
{
public:
	CadburyFactory();
	~CadburyFactory();
	Confectionary *createChocolate();
	Confectionary *createAeratedChocolate();
};

#endif
