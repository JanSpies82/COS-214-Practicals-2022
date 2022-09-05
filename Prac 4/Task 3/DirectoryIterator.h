#ifndef DIRECTORYITERATOR_H
#define DIRECTORYITERATOR_H
#include "Directory.h"
#include "NodeIterator.h"
class DirectoryIterator : public NodeIterator
{
public:
	DirectoryIterator();
	~DirectoryIterator();
	void first();
	void next();
	bool hasNext();
	Directory *current();
	void handle();
};

#endif
