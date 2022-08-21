#include <exception>
using namespace std;

#ifndef __ConfectionaryFactory_h__
#define __ConfectionaryFactory_h__

class ConfectionaryFactory;

__abstract class ConfectionaryFactory
{

	public: virtual Confectionary* createChocolate() = 0;

	public: virtual Confectionary* createAeratedChocolate() = 0;
};

#endif
