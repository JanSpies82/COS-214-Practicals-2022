#ifndef ASYNCHRONOUSDIRECTORY_H
#define ASYNCHRONOUSDIRECTORY_H
#include "Directory.h"

class AsynchronousDirectory : public Directory
{
public:
    AsynchronousDirectory(std::string name);
    ~AsynchronousDirectory();
    void addChild(Node *child);
    Node *access(std::string name);
};
#endif