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
    virtual void listDirectory();
    virtual void listFile();
    virtual bool isEmpty();
    NodeIterator *createIterator();
    void print(bool files);

protected:
    std::vector<Node *> *children;
};
#endif