#ifndef ADDON_H
#define ADDON_H
#include "Component.h"

class AddOn : public Component
{
public:
    AddOn(double price, Component *component);
    ~AddOn();
    Component *getComponent();
    void setComponent(Component *component);
    bool canAddDiscount();
    virtual bool isDiscountable() = 0;
    void setDiscount(double discount);
    virtual double getPrice();
    virtual std::string getDescription() = 0;
    virtual bool hasNote() = 0;
    virtual bool hasCard() = 0;

protected:
    Component *component;
    double price;
    double discount;
};
#endif