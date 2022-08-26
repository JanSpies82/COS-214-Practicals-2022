#ifndef VALENTINESDAY_H
#define VALENTINESDAY_H
#include "Discount.h"

class ValentinesDay : public Discount
{
public:
    ValentinesDay(Component *component);
    virtual ~ValentinesDay();
};
#endif // VALENTINESDAY_H