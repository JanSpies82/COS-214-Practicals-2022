#include <exception>
using namespace std;

#ifndef __DirectoryIterator_h__
#define __DirectoryIterator_h__

// #include "Directory.h"
#include "NodeIterator.h"

class Directory;
// class NodeIterator;
class DirectoryIterator;

class DirectoryIterator: public NodeIterator
{
	private: Directory* directory;
	public: Directory* unnamed_Directory_;

	public: void first();

	public: void next();

	public: bool hasNext();

	public: Directory* current();

	public: void handle();
};

#endif
