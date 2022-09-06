#include "NodeIterator.h"
#include "Node.h"
using namespace std;

NodeIterator::NodeIterator(Node *n)
{
	node = n;
	parent = (Directory *)n->getParent();
}

NodeIterator::~NodeIterator()
{
}