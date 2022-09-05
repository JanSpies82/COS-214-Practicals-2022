#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include <vector>
class File;
class NodeIterator;
class Directory : public Node
{
public:
    Directory();
    Directory(std::string name, bool synchronous);
    virtual ~Directory();
    virtual void addChild(Node *child) = 0;
    void removeChild(std::string name);
    std::vector<Node *> *getChildren();
    std::string listContents();
    virtual Node *access(std::string name) = 0;
    virtual void addDirectory(Directory *directory);
    virtual void addFile(File *file);
    virtual void removeDirectory(std::string name);
    virtual void removeFile(std::string name);
    virtual bool listDirectory();
    virtual bool listFile();
    virtual bool isEmpty();
    NodeIterator *createIterator();
    std::string print(int depth=0);

protected:
    std::vector<Node *> *children;
};
#endif