#include "CadburyFactory.h"
using namespace std;

CadburyFactory::CadburyFactory(){};
CadburyFactory::~CadburyFactory(){};
Confectionary *CadburyFactory::createChocolate(bool slab)
{
	cout << "CadburyFactory creating chocolate" << endl;
	return new DairyMilk(slab);
}

Confectionary *CadburyFactory::createAeratedChocolate(int bubblespccm)
{
	cout << "CadburyFactory creating aerated chocolate" << endl;
	return new DairyMilkBubbly(bubblespccm);
}
