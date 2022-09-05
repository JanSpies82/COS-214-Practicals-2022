#ifndef NODEITERATOR_H
#define NODEITERATOR_H
#include "Node.h"
class NodeIterator
{
public:
	NodeIterator();
	virtual ~NodeIterator();
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual Node *current() = 0;
	virtual void handle() = 0;

protected:
	Node *node;
};

#endif
