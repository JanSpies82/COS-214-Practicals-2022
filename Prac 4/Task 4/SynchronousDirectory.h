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
    void addDirectory(Directory *directory);
    void addFile(File *file);
    void removeDirectory(std::string name);
    void removeFile(std::string name);
    bool listDirectory();
    bool listFile();
    bool isEmpty();
};
#endif