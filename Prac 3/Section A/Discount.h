#ifndef DISCOUNT_H
#define DISCOUNT_H
#include "Component.h"

class Discount : public Component
{
public:
    Discount(std::string description, std::string date, double discount, Component *component);
    virtual ~Discount();
    std::string getDescription();
    double getPrice();
    std::string getDate();
    Component* getComponent();
    void setComponent(Component* component);
    bool canAddDiscount();
    bool isDiscountable();
    void setDiscount(double discount);

protected:
    std::string description;
    std::string date;
    Component* component;
};
#endif