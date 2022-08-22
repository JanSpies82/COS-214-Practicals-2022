#include "LindtFactory.h"
#include "AeratedChocolate.h"
#include "EmptyConfec.h"
using namespace std;

LindtFactory::LindtFactory(){};
LindtFactory::~LindtFactory(){};

Confectionary *LindtFactory::createChocolate(bool slab)
{
	return new Lindor(slab);
}

// TODO decide what this function does
Confectionary *LindtFactory::createAeratedChocolate(int bubblespccm)
{
	return new EmptyConfec();
}
