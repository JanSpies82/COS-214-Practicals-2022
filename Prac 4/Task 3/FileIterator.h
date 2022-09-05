#include <exception>
using namespace std;

#ifndef __FileIterator_h__
#define __FileIterator_h__

// #include "File.h"
#include "NodeIterator.h"

class File;
// class NodeIterator;
class FileIterator;

class FileIterator: public NodeIterator
{
	private: File* file;
	public: File* unnamed_File_;

	public: void next();

	public: void first();

	public: bool hasNext();

	public: File* current();

	public: void handle();
};

#endif
