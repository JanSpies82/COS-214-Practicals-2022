#ifndef FLOWER_H
#define FLOWER_H
#include "AddOn.h"

class Flower : public AddOn
{
public:
    Flower(std::string variety, Component *component);
    ~Flower();
    bool isDiscountable();
    std::string getDescription();
    bool hasNote();
    bool hasCard();

protected:
    std::string variety;
};
#endif // FLOWER_H