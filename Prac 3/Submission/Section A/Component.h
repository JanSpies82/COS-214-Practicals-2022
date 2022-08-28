#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <iostream>
class Component
{
public:
    Component();
    virtual ~Component();
    virtual std::string getDescription() = 0;
    virtual double getPrice() = 0;
    virtual bool canAddDiscount() = 0;
    virtual void setDiscount(double discount) = 0;
    double getDiscount();
    virtual bool isDiscountable() = 0;
    virtual bool hasNote() = 0;
    virtual bool hasCard() = 0;

protected:
    double discount;
};
#endif