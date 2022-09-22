#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Root.h"
class Driver
{
public:
    Driver();
    ~Driver();
    bool isActive();
    void performAction();

private:
    Root* root;
    bool active;
    void createHeader();
    int getOperation();
    void addNewDirec();
};
#endif