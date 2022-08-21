#include <exception>
using namespace std;

#ifndef __NestleFactory_h__
#define __NestleFactory_h__

#include "ConfectionaryFactory.h"

// class ConfectionaryFactory;
class NestleFactory;

class NestleFactory: public ConfectionaryFactory
{

	public: Confectionary* createChocolate();

	public: Confectionary* createAeratedChocolate();
};

#endif
