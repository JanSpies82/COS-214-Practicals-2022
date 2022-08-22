#include "NestleFactory.h"
using namespace std;

NestleFactory::NestleFactory(){};
NestleFactory::~NestleFactory(){};

Confectionary *NestleFactory::createChocolate(bool slab)
{
	return new Milkybar(slab);
}

Confectionary *NestleFactory::createAeratedChocolate(int bubblespccm)
{
	return new Aero(bubblespccm);
}
