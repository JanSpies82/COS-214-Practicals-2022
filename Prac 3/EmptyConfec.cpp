#include "EmptyConfec.h"
using namespace std;

EmptyConfec::EmptyConfec() : Confectionary()
{
    manufacturer = "none";
    price = 0;
    type = "none";
    id = -1;
}
EmptyConfec::~EmptyConfec()
{
}

string EmptyConfec::getDescription(){
    return "This is an empty confectionary item";
}