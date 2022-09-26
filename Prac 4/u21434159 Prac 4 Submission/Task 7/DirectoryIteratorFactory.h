#ifndef DIRECTORYITERATORFACTORY_H
#define DIRECTORYITERATORFACTORY_H
#include "IteratorFactory.h"
#include "DirectoryIterator.h"
class DirectoryIteratorFactory : public IteratorFactory
{
public:
	DirectoryIteratorFactory();
	~DirectoryIteratorFactory();
	NodeIterator *createIterator(Node* n);
};

#endif
