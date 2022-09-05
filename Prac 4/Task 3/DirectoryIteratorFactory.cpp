#include "DirectoryIteratorFactory.h"
using namespace std;

DirectoryIteratorFactory::DirectoryIteratorFactory()
{
}

DirectoryIteratorFactory::~DirectoryIteratorFactory()
{
}
NodeIterator *DirectoryIteratorFactory::createIterator()
{
	return new DirectoryIterator();
}
