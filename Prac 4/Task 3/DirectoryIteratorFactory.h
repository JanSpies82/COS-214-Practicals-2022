#include <exception>
using namespace std;

#ifndef __DirectoryIteratorFactory_h__
#define __DirectoryIteratorFactory_h__

#include "IteratorFactory.h"

// class IteratorFactory;
class DirectoryIteratorFactory;

class DirectoryIteratorFactory: public IteratorFactory
{

	public: NodeIterator* createIterator();
};

#endif
