#include "Lindor.h"
using namespace std;

Lindor::Lindor(bool slab) : Chocolate("Lindt", 25, slab)
{
    cout << "New Lindor created as " << (slab ? "slab" : "minibar") << endl;
}

Lindor::~Lindor()
{
    cout << "Lindor destroyed" << endl;
}