#include "CadburyFactory.h"
using namespace std;

CadburyFactory::CadburyFactory(){};
CadburyFactory::~CadburyFactory(){};
Confectionary *CadburyFactory::createChocolate()
{
	return new DairyMilk();
}

Confectionary *CadburyFactory::createAeratedChocolate()
{
	return NULL;
}
