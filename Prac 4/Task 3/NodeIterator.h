#include <exception>
using namespace std;

#ifndef __NodeIterator_h__
#define __NodeIterator_h__

class NodeIterator;

__abstract class NodeIterator
{

	public: virtual void first() = 0;

	public: virtual void next() = 0;

	public: virtual bool hasNext() = 0;

	public: virtual Node* current() = 0;

	public: virtual void handle() = 0;
};

#endif
