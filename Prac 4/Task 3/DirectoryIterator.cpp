#include "DirectoryIterator.h"
#include "FileIterator.h"
using namespace std;

DirectoryIterator::DirectoryIterator(Node *n) : NodeIterator(n)
{
	parent = (Directory *)n->getParent();
}

DirectoryIterator::~DirectoryIterator()
{
}

void DirectoryIterator::first()
{
	Node *ptr = node;
	while (ptr->getParent() != NULL)
	{
		ptr = ptr->getParent();
	}
	node = ptr;
}

NodeIterator *DirectoryIterator::next()
{
	if (parent == NULL)
		node = NULL;
	else
	{
		int i = 0;
		while (parent->getChild(i) != node)
			i++;
		if (i < parent->getChildrenCount() - 1)
			node = parent->getChild(i + 1);
		else
			node = NULL;
	}
	if (node != NULL)
		if (node->getType() != "Directory")
		{
			return (NodeIterator *)new FileIterator(node);
			delete this;
		}
	return this;
}

bool DirectoryIterator::hasNext()
{
	if (parent == NULL)
		return false;
	int i = 0;
	while (parent->getChild(i) != node)
		i++;
	if (i >= parent->getChildrenCount() - 1)
		return false;
	return true;
}

Directory *DirectoryIterator::current()
{ 
	return (Directory*) node;
}
