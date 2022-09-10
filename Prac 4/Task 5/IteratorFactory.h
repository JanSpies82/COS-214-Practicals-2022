#ifndef ITERATORFACTORY_H
#define ITERATORFACTORY_H
#include "NodeIterator.h"
class Node;
class IteratorFactory
{
public:
	IteratorFactory();
	virtual ~IteratorFactory();
	virtual NodeIterator *createIterator(Node* node) = 0;
};

#endif
