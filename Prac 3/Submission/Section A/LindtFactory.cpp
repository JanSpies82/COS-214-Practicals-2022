#include "LindtFactory.h"
#include "AeratedChocolate.h"
#include "EmptyConfec.h"
using namespace std;

LindtFactory::LindtFactory(){};
LindtFactory::~LindtFactory(){};

Confectionary *LindtFactory::createChocolate(bool slab)
{
	cout << "LindtFactory creating chocolate" << endl;
	return new Lindor(slab);
}

Confectionary *LindtFactory::createAeratedChocolate(int bubblespccm)
{
	cout << "LindtFactory creating aerated chocolate" << endl;
	return new EmptyConfec();
}
