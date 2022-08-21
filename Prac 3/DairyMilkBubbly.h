#include <exception>
#include <string>
using namespace std;

#ifndef __DairyMilkBubbly_h__
#define __DairyMilkBubbly_h__

#include "AeratedChocolate.h"

// class AeratedChocolate;
class DairyMilkBubbly;

class DairyMilkBubbly: public AeratedChocolate
{

	public: DairyMilkBubbly(string manufacturer, double price, int bubblespccm);
};

#endif
