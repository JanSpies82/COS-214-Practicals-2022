#ifndef RIBBON_H
#define RIBBON_H
#include "AddOn.h"

class Ribbon : public AddOn
{
public:
    Ribbon(std::string color,Component *component);
    ~Ribbon();
    bool isDiscountable();
    std::string getDescription();
    bool hasNote();
    bool hasCard();
private:
    std::string color;
};
#endif