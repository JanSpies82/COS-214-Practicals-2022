#include <exception>
#include <string>
using namespace std;

#ifndef __Aero_h__
#define __Aero_h__

#include "AeratedChocolate.h"

// class AeratedChocolate;
class Aero;

class Aero: public AeratedChocolate
{

	public: Aero(string manufacturer, double price, string bubblespccm);
};

#endif
