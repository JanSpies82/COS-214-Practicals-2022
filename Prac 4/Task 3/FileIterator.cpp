#include "FileIterator.h"
using namespace std;

FileIterator::FileIterator(Node *n) : NodeIterator(n)
{
}

FileIterator::~FileIterator()
{
}
NodeIterator* FileIterator::next()
{
	throw "Not yet implemented";
}

void FileIterator::first()
{
	Node *ptr = node;
	while (ptr->getParent() != NULL)
	{
		ptr = ptr->getParent();
	}
	node = ptr;
}

bool FileIterator::hasNext()
{
	throw "Not yet implemented";
}

File *FileIterator::current()
{
	throw "Not yet implemented";
}
