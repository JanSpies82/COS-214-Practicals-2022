#ifndef FLOWER_H
#define FLOWER_H
#include "AddOn.h"

class Flower : public AddOn
{
public:
    Flower(std::string variety, Component *component);
    ~Flower();
    bool isDiscountable();
    double getPrice();
    std::string getDescription();

protected:
    std::string variety;
};
#endif // FLOWER_H