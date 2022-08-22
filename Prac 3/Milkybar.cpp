#include "Milkybar.h"
using namespace std;

Milkybar::Milkybar(bool slab) : Chocolate("Nestle", 15, slab)
{
    cout << "New Milkybar created as " << (slab ? "slab" : "minibar") << endl;
}

Milkybar::~Milkybar()
{
    cout << "Milkybar destroyed" << endl;
}