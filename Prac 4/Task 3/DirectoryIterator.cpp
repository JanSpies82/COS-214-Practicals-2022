#include "DirectoryIterator.h"
#include "FileIterator.h"
using namespace std;

DirectoryIterator::DirectoryIterator(Node *n) : NodeIterator(n)
{
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
	parent = NULL;
	node->resetVisit();
}

// NodeIterator next will return a new NodeIterator object,
// which is of the correct ConcreteIterator type for the
// current(previously next) node

// TODO - implement next & hasnext functions such that they can
// perform breadth first traversal
// set call parent->visit() in getCurrent function
// When you reach the last child of the parent, you should
// check whether one of the children is a directory and enter it
// parent->isVisited() is false if there is a child directory
// child->isVisited() is false if the child is a directory
NodeIterator *DirectoryIterator::next()
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
					node = parent->getChild(h);
					return handle(node);
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
							return handle(node);
						}
						g++;
					}
				}
			}
		}
		else
		{
			node = parent->getChild(i);
			return handle(node); // if there are more children
		}
	}
	node = ((Directory *)node)->getChild(0);
	return handle(node); // if current node is root
}

bool DirectoryIterator::hasNext()
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
	return node->isVisited(); // if current node is root
}

Directory *DirectoryIterator::current()
{
	return (Directory *)node;
}

NodeIterator *DirectoryIterator::handle(Node *n)
{
	n->visit();
	if (n->getType() == "Directory")
		return (NodeIterator *)this;
	else
	{
		return (NodeIterator *)new FileIterator(n);
		delete this;
	}
}