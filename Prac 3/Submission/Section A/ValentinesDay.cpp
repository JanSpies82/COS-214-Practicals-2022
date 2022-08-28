#include "ValentinesDay.h"
using namespace std;

ValentinesDay::ValentinesDay(Component *component) : Discount("Valentine's Day", "14 February", 0.05, component)
{
}

ValentinesDay::~ValentinesDay()
{
    delete component;
}