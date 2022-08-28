#include "NestleFactory.h"
using namespace std;

NestleFactory::NestleFactory(){};
NestleFactory::~NestleFactory(){};

Confectionary *NestleFactory::createChocolate(bool slab)
{
	cout << "NestleFactory creating chocolate" << endl;
	return new Milkybar(slab);
}

Confectionary *NestleFactory::createAeratedChocolate(int bubblespccm)
{
	cout << "NestleFactory creating aerated chocolate" << endl;
	return new Aero(bubblespccm);
}
