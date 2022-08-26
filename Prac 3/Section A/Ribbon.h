#ifndef RIBBON_H
#define RIBBON_H
#include "AddOn.h"

class Ribbon : public AddOn
{
public:
    Ribbon(std::string color,Component *component);
    ~Ribbon();
    bool isDiscountable();
    double getPrice();
    std::string getDescription();
private:
    std::string color;
};
#endif