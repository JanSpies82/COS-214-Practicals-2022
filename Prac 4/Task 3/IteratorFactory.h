#include <exception>
using namespace std;

#ifndef __IteratorFactory_h__
#define __IteratorFactory_h__

class IteratorFactory;

__abstract class IteratorFactory
{

	public: virtual NodeIterator* createIterator() = 0;
};

#endif
