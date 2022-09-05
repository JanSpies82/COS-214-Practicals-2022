#ifndef NODE_H
#define NODE_H
#include <string>
#include <chrono>
#include <stdexcept>
#include <iostream>
#include "NodeIterator.h"
class Node
{
public:
    Node();
    Node(std::string name, bool synchronous, std::string type);
    virtual ~Node();
    std::string getName();
    void setName(std::string name);
    double getLastModified();
    std::string timeToString(double time);
    bool isSynchronous();
    std::string getType();
    virtual NodeIterator *createIterator() = 0;
    virtual void print(bool files) = 0;

protected:
    std::string name;
    double lastModified;
    bool synchronous;
    std::string type;
};
#endif