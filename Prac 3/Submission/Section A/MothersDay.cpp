#include "MothersDay.h"
using namespace std;

MothersDay::MothersDay(Component *component) : Discount("Mother's Day", "14 May", 0.035, component)
{
}

MothersDay::~MothersDay()
{
    delete component;
}