#include <exception>
using namespace std;

#ifndef __FileIteratorFactory_h__
#define __FileIteratorFactory_h__

#include "IteratorFactory.h"

// class IteratorFactory;
class FileIteratorFactory;

class FileIteratorFactory: public IteratorFactory
{

	public: NodeIterator* createIterator();
};

#endif
