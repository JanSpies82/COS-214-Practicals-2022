#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <iostream>
class Component
{
public:
    Component();
    Component();
    virtual ~Component();
    virtual std::string getDescription() = 0;    
};
#endif