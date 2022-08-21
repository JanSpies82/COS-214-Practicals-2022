#include <exception>
using namespace std;

#ifndef __CadburyFactory_h__
#define __CadburyFactory_h__

#include "ConfectionaryFactory.h"

// class ConfectionaryFactory;
class CadburyFactory;

class CadburyFactory: public ConfectionaryFactory
{

	public: Confectionary* createChocolate();

	public: Confectionary* createAeratedChocolate();
};

#endif
