#ifndef FILEITERATORFACTORY_H
#define FILEITERATORFACTORY_H
#include "IteratorFactory.h"
#include "FileIterator.h"
class FileIteratorFactory : public IteratorFactory
{
public:
	FileIteratorFactory();
	~FileIteratorFactory();
	NodeIterator *createIterator();
};
#endif
