#ifndef FILEITERATOR_H
#define FILEITERATOR_H
#include "NodeIterator.h"
#include "File.h"
class FileIterator : public NodeIterator
{
public:
	FileIterator(Node* n);
	~FileIterator();
	NodeIterator* next();
	void first();
	bool hasNext();
	File *current();
private:
	NodeIterator *handle(Node *n);
};

#endif
