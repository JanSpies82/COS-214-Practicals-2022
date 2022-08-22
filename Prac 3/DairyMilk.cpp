#include "DairyMilk.h"
using namespace std;

DairyMilk::DairyMilk(bool slab) : Chocolate("Cadbury", 17, slab)
{
    cout << "New DairyMilk created as " << (slab ? "slab" : "minibar") << endl;
}
DairyMilk::~DairyMilk()
{
    cout << "DairyMilk destroyed" << endl;
}