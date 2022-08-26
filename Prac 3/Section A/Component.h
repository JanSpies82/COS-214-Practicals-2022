#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <iostream>
class Component
{
public:
    Component(double price, std::string type);
    Component();
    virtual ~Component();
    virtual std::string getDescription() = 0;
    virtual double getPrice() = 0;
    std::string getType();
    void setPrice(double price);
    void setType(std::string type);

protected:
    double price;
    std::string type;
};
#endif