#include "EmptyConfec.h"
using namespace std;

EmptyConfec::EmptyConfec() : Confectionary()
{
    manufacturer = "none";
    price = 0;
    type = "none";
    id = -1;

    cout << "Empty Confectionary created" << endl;
}
EmptyConfec::~EmptyConfec()
{
    cout << "Empty Confectionary destroyed" << endl;
}

string EmptyConfec::getDescription()
{
    return "This is an empty confectionary item\n";
}