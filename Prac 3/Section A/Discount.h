#ifndef DISCOUNT_H
#define DISCOUNT_H
#include "Component.h"

class Discount : public Component
{
public:
    Discount(std::string description, std::string date, double discount);
    virtual ~Discount();
    virtual std::string getDescription();
    virtual double getPrice();
    virtual std::string getDate();
    virtual double getDiscount();

protected:
    std::string description;
    std::string date;
    double discount;
};
#endif