#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include <vector>
class File;
class NodeIterator;
class IteratorManager;
class Directory : public Node
{
public:
    friend class DirectoryIterator;
    Directory();
    Directory(std::string name, bool synchronous, Node *parent = NULL);
    virtual ~Directory();
    virtual void addChild(Node *child) = 0;
    void removeChild(std::string name);
    Node *getChild(int i);
    int getChildrenCount();
    std::string listContents();
    virtual Node *access(std::string name) = 0;
    virtual void addDirectory(Directory *directory);
    virtual void addFile(File *file);
    virtual void removeDirectory(std::string name);
    virtual void removeFile(std::string name);
    virtual bool listDirectory();
    virtual bool listFile();
    virtual bool isEmpty();
    IteratorManager *createIteratorManager();
    std::string print(int depth = 0);
    void visit();
    void resetVisit();
    bool isVisited();

protected:
    std::vector<Node *> *children;
};
#endif