#ifndef DIRECTORYITERATOR_H
#define DIRECTORYITERATOR_H
#include "Directory.h"
#include "NodeIterator.h"
class DirectoryIterator : public NodeIterator
{
public:
	DirectoryIterator(Node* n );
	~DirectoryIterator();
	void first();
	NodeIterator* next();
	bool hasNext();
	Directory *current();
};

#endif
