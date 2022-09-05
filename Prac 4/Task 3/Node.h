#ifndef NODE_H
#define NODE_H
#include <string>
#include <chrono>
#include <stdexcept>
#include <iostream>
#include "NodeIterator.h"

class Directory;
class File;
class Node
{
public:
    Node();
    Node(std::string name, bool synchronous, std::string type, Node *parent);
    virtual ~Node();
    std::string getName();
    void setName(std::string name);
    double getLastModified();
    std::string timeToString(double time);
    bool isSynchronous();
    std::string getType();
    virtual NodeIterator *createIterator() = 0;
    virtual std::string print(int depth = 0) = 0;
    virtual void addDirectory(Directory *directory) = 0;
    virtual void addFile(File *file) = 0;
    virtual void removeDirectory(std::string name) = 0;
    virtual void removeFile(std::string name) = 0;
    virtual bool listDirectory() = 0;
    virtual bool listFile() = 0;
    virtual bool isEmpty() = 0;
    Node *getParent();
    void setParent(Node *parent);
    virtual void visit() = 0;
    virtual bool isVisited();
    virtual void resetVisit() = 0;

protected:
    std::string name;
    double lastModified;
    bool synchronous;
    std::string type;
    Node *parent;
    bool visited;
};
#endif