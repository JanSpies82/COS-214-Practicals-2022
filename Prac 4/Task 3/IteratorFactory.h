#ifndef ITERATORFACTORY_H
#define ITERATORFACTORY_H
#include "NodeIterator.h"
class IteratorFactory
{
public:
	IteratorFactory();
	virtual ~IteratorFactory();
	virtual NodeIterator *createIterator() = 0;
};

#endif
