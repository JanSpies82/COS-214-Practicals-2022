#ifndef CADBURYFACTORY_H
#define CADBURYFACTORY_H

#include "ConfectionaryFactory.h"
#include "DairyMilk.h"
#include "DairymilkBubbly.h"

class CadburyFactory : public ConfectionaryFactory
{
public:
	CadburyFactory();
	~CadburyFactory();
	Confectionary *createChocolate(bool slab);
	Confectionary *createAeratedChocolate(int bubblespccm);
};

#endif
