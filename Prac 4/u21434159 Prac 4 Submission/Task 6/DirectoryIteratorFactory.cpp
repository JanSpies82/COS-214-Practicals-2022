#include "DirectoryIteratorFactory.h"
class Node;
using namespace std;

DirectoryIteratorFactory::DirectoryIteratorFactory()
{
}

DirectoryIteratorFactory::~DirectoryIteratorFactory()
{
}
NodeIterator *DirectoryIteratorFactory::createIterator(Node* n)
{
	return new DirectoryIterator(n);
}
