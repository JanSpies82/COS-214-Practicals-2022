#ifndef MOTHERSDAY_H
#define MOTHERSDAY_H
#include "Discount.h"

class MothersDay : public Discount
{
public:
    MothersDay(Component *component);
    ~MothersDay();
};
#endif // MOTHERSDAY_H