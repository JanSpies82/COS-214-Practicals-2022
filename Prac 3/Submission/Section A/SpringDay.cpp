#include "SpringDay.h"
using namespace std;

SpringDay::SpringDay(Component *component) : Discount("Spring Day", "1 September", 0.07, component)
{
}

SpringDay::~SpringDay()
{
    delete component;
}