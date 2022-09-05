#ifndef FILEITERATOR_H
#define FILEITERATOR_H
#include "NodeIterator.h"
#include "File.h"
class FileIterator : public NodeIterator
{
public:
	FileIterator();
	~FileIterator();
	void next();
	void first();
	bool hasNext();
	File *current();
	void handle();
};

#endif
