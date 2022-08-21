#include <exception>
#include <string>
using namespace std;

#ifndef __Confectionary_h__
#define __Confectionary_h__

class Confectionary;

__abstract class Confectionary
{
	private: string manufacturer;
	private: double price;
	private: string type;
	private: int id;
	private: int counter;

	public: Confectionary(string manufacturer, double price, string type);

	public: string getDescription();
};

#endif
