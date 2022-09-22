#include "FileIteratorFactory.h"
class Node;
using namespace std;

FileIteratorFactory::FileIteratorFactory()
{
}

FileIteratorFactory::~FileIteratorFactory()
{
}
NodeIterator *FileIteratorFactory::createIterator(Node* n)
{
	return new FileIterator(n);
}
