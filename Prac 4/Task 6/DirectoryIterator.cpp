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
	node->visit();
}

Node *DirectoryIterator::next()
{
	// if (hasNext())
	// cout << YELLOW << node->getName() << " has a next " << RESET << endl;
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
						// cout << BLUE << "Calling " << ((Directory *)ptr)->getChild(g)->getName() << RESET << endl;
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
				if (!parent->getChild(h)->isVisited())
				{ // if a child directory is not visited
					// cout << BLUE << "1" << RESET << endl;
					return true;
				}
				h++;
			}
			// if all children are visited, move back up tree and look for unvisited nodes
			Node *ptr = node;
			while (ptr->getParent() != NULL)
			{
				ptr = ptr->getParent();
				if (!ptr->isVisited())
				{
					// cout << RED << "returning true for " << ptr->getName() << RESET << endl;
					return true;
				}
			}
			// cout << RED << "1" << RESET << endl;
			return false;
		}
		else
		{
			// cout << BLUE << "3" << RESET << endl;
			return true; // if there are more children
		}
	}
	// cout << RED << "4" << RESET << endl;
	return !node->isVisited(); // if current node is root
}

Directory *DirectoryIterator::current()
{
	return (Directory *)node;
}

// void DirectoryIterator::handle(Node *n)
// {
// 	n->visit();
// 	if (n->getType() == "Directory")
// 	{
// 		cout << YELLOW << n->getName() << " is a " << n->getType() << RESET << endl;
// 		setNext(this);
// 	}
// 	else
// 	{
// 		cout << YELLOW << n->getName() << " is a " << n->getType() << RESET << endl;
// 		setNext(new FileIterator(n));
// 	}
// }

// string DirectoryIterator::iType()
// {
// 	return "DirectoryIterator";
// }