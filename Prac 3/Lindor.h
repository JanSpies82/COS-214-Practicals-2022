#include <exception>
#include <string>
using namespace std;

#ifndef __Lindor_h__
#define __Lindor_h__

#include "Chocolate.h"

// class Chocolate;
class Lindor;

class Lindor: public Chocolate
{

	public: Lindor(string manufacturer, double price, bool slab);
};

#endif
