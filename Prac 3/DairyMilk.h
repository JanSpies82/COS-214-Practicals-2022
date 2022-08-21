#include <exception>
#include <string>
using namespace std;

#ifndef __DairyMilk_h__
#define __DairyMilk_h__

#include "Chocolate.h"

// class Chocolate;
class DairyMilk;

class DairyMilk: public Chocolate
{

	public: DairyMilk(string manufacturer, double price, bool slab);
};

#endif
