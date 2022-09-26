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
    Root *root;
    Directory *current;
    bool active;
    void createHeader();
    int getOperation();
    void addNewDirec();
    void addNewFile();
    void deleteDirec();
    void deleteFile();
    void moveToDirec();
    void addSnapshot();
    void deleteSnapshots();
    void restoreSnapshot();
};
#endif