#include "NestleFactory.h"
using namespace std;

NestleFactory::NestleFactory(){};
NestleFactory::~NestleFactory(){};

Confectionary *NestleFactory::createChocolate()
{
	return NULL;
}

Confectionary *NestleFactory::createAeratedChocolate()
{
	return NULL;
}
