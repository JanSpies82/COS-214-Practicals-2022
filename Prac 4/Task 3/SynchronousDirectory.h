#ifndef SYNCHRONOUSDIRECTORY_H
#define SYNCHRONOUSDIRECTORY_H
#include "Directory.h"
class SynchronousDirectory : public Directory
{
public:
    SynchronousDirectory(std::string name);
    ~SynchronousDirectory();
    void addChild(Node *child);
    Node *access(std::string name);
};
#endif