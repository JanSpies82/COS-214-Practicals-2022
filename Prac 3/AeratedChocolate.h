#include <exception>
#include <string>
using namespace std;

#ifndef __AeratedChocolate_h__
#define __AeratedChocolate_h__

#include "Confectionary.h"

// class Confectionary;
class AeratedChocolate;

class AeratedChocolate: public Confectionary
{
	private: int bubblespccm;

	public: AeratedChocolate(string manufacturer, double price, int bubblespccm);

	public: string getDescription();
};

#endif
