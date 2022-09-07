#include "FileIterator.h"
#include "DirectoryIterator.h"
using namespace std;

FileIterator::FileIterator(Node *n) : NodeIterator(n)
{
}

FileIterator::~FileIterator()
{
}
Node *FileIterator::next()
{
	parent = (Directory *)node->getParent();
	if (!hasNext())
		throw logic_error("No next element");

	if (parent != NULL)
	{
		int i = 0;
		while (parent->getChild(i) != node)
			i++;
		i++;
		if (i >= parent->getChildrenCount()) // if no more children left
		{
			int h = 0;
			while (h < parent->getChildrenCount())
			{
				if (!parent->getChild(h)->isVisited())
				{ // if a child directory is not visited
					node = ((Directory *)parent->getChild(h))->getChild(0);
					return node;
				}
				h++;
			}
			Node *ptr = node;
			while (ptr->getParent() != NULL)
			{
				ptr = ptr->getParent();
				if (!ptr->isVisited())
				{
					int g = 0;
					while (g < ((Directory *)ptr)->getChildrenCount())
					{
						if (!((Directory *)ptr)->getChild(g)->isVisited())
						{
							node = ((Directory *)((Directory *)ptr)->getChild(g))->getChild(0);
							return node;
						}
						g++;
					}
				}
			}
		}
		else
		{
			node = parent->getChild(i);
			return node; // if there are more children
		}
	}
	node = ((Directory *)node)->getChild(0);
	return node; // if current node is root
}

void FileIterator::first()
{
	Node *ptr = node;
	while (ptr->getParent() != NULL)
	{
		ptr = ptr->getParent();
	}
	node = ptr;
	parent = NULL;
	node->resetVisit();
	node->visit();
}

bool FileIterator::hasNext()
{
	parent = (Directory *)node->getParent();
	if (parent != NULL)
	{
		int i = 0;
		while (parent->getChild(i) != node)
			i++;
		i++;
		if (i >= parent->getChildrenCount()) // if no more children left
		{
			int h = 0;
			while (h < parent->getChildrenCount())
			{
				if (!parent->getChild(h)->isVisited()) // if a child directory is not visited
					return true;
				h++;
			}
			// if all children are visited, move back up tree and look for unvisited nodes
			Node *ptr = node;
			while (ptr->getParent() != NULL)
			{
				ptr = ptr->getParent();
				if (!ptr->isVisited())
					return true;
			}
			return false;
		}
		else
			return true; // if there are more children
	}
	return !node->isVisited(); // if current node is root
}

File *FileIterator::current()
{
	return (File *)node;
}

// NodeIterator *FileIterator::handle(Node *n)
// {
// 	n->visit();
// 	if (n->getType() == "File")
// 		return (NodeIterator *)this;
// 	else
// 	{
// 		return (NodeIterator *)new DirectoryIterator(n);
// 		delete this;
// 	}
// }

// string FileIterator::iType()
// {
// 	return "FileIterator";
// }