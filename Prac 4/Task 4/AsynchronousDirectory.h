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
    void addDirectory(Directory *directory);
    void addFile(File *file);
    void removeDirectory(std::string name);
    void removeFile(std::string name);
    bool listDirectory();
    bool listFile();
    bool isEmpty();
    void setState(State *state);
};
#endif