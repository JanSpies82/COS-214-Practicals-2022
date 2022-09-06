#ifndef NODEITERATOR_H
#define NODEITERATOR_H
class Node;
class Directory;
class NodeIterator
{
public:
	NodeIterator(Node *n);
	virtual ~NodeIterator();
	virtual void first() = 0;
	virtual NodeIterator *next() = 0;
	virtual bool hasNext() = 0;
	virtual Node *current() = 0;

protected:
	Node *node;
	Directory *parent;
};

#endif

// NodeIterator next will return a new NodeIterator object,
// which is of the correct ConcreteIterator type for the
// current(previously next) node

// When operations are called on NodeIterator objects they
// are delegated to the correct ConcreteIterator object
// and Concrete is returned and swapped in the next function

// TODO - implement next & hasnext functions such that they can
// perform breadth first traversal
// set call parent->visit() in getCurrent function
