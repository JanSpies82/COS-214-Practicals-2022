#include <exception>
using namespace std;

#include "LindtFactory.h"
#include "ConfectionaryFactory.h"

Confectionary* LindtFactory::createChocolate() {
	throw "Not yet implemented";
}

Confectionary* LindtFactory::createAeratedChocolate() {
	throw "Not yet implemented";
}

