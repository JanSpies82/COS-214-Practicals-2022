#include <exception>
#include <string>
using namespace std;

#ifndef __Milkybar_h__
#define __Milkybar_h__

#include "Chocolate.h"

// class Chocolate;
class Milkybar;

class Milkybar: public Chocolate
{

	public: Milkybar(string manufacturer, double price, bool slab);
};

#endif
