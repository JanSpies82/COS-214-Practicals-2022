#include "CadburyFactory.h"
using namespace std;

CadburyFactory::CadburyFactory(){};
CadburyFactory::~CadburyFactory(){};
Confectionary *CadburyFactory::createChocolate(bool slab)
{
	return new DairyMilk(slab);
}

Confectionary *CadburyFactory::createAeratedChocolate(int bubblespccm)
{
	return new DairyMilkBubbly(bubblespccm);
}
