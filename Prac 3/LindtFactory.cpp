#include "LindtFactory.h"
using namespace std;

LindtFactory::LindtFactory(){};
LindtFactory::~LindtFactory(){};

Confectionary *LindtFactory::createChocolate(bool slab)
{
	return new Lindor(slab);
}

Confectionary *LindtFactory::createAeratedChocolate(int bubblespccm)
{
	return NULL;
}
