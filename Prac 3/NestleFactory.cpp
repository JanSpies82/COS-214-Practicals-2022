#include <exception>
using namespace std;

#include "NestleFactory.h"
#include "ConfectionaryFactory.h"

Confectionary* NestleFactory::createChocolate() {
	throw "Not yet implemented";
}

Confectionary* NestleFactory::createAeratedChocolate() {
	throw "Not yet implemented";
}

