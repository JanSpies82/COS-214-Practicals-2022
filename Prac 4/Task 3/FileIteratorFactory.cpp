#include "FileIteratorFactory.h"
using namespace std;

FileIteratorFactory::FileIteratorFactory()
{
}

FileIteratorFactory::~FileIteratorFactory()
{
}
NodeIterator *FileIteratorFactory::createIterator()
{
	return new FileIterator();
}
