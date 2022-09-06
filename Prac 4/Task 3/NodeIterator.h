#ifndef NODEITERATOR_H
#define NODEITERATOR_H
#include <string>
class Node;
class Directory;
class NodeIterator
{
public:
	const std::string RED = "\x1B[31m";
	const std::string GREEN = "\x1B[32m";
	const std::string YELLOW = "\x1B[33m";
	const std::string BLUE = "\x1B[34m";
	const std::string CYAN = "\x1B[36m";
	const std::string RESET = "\x1B[0m";
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
