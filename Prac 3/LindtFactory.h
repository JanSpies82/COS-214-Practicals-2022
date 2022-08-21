#include <exception>
using namespace std;

#ifndef __LindtFactory_h__
#define __LindtFactory_h__

#include "ConfectionaryFactory.h"

// class ConfectionaryFactory;
class LindtFactory;

class LindtFactory: public ConfectionaryFactory
{

	public: Confectionary* createChocolate();

	public: Confectionary* createAeratedChocolate();
};

#endif
