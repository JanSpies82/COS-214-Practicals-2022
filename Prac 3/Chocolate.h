#include <exception>
#include <string>
using namespace std;

#ifndef __Chocolate_h__
#define __Chocolate_h__

#include "Confectionary.h"

// class Confectionary;
class Chocolate;

class Chocolate: public Confectionary
{
	private: bool slab;

	public: Chocolate(string manufacturer, double price, bool slab);

	public: string getDescription();
};

#endif
