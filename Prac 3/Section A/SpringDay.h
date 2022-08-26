#ifndef SPRINGDAY_H
#define SPRINGDAY_H
#include "Discount.h"

class SpringDay : public Discount
{
public:
    SpringDay(Component *component);
    ~SpringDay();
};
#endif // SPRINGDAY_H