#ifndef NODE_H
#define NODE_H
#include <string>
#include <chrono>
#include <stdexcept>
#include <iostream>
#include <string>
#include "NodeIterator.h"

class Directory;
class File;
class IteratorManager;
class State;
class Observer;
class Node
{
    friend class State;

public:
    const std::string RED = "\x1B[31m";
    const std::string GREEN = "\x1B[32m";
    const std::string YELLOW = "\x1B[33m";
    const std::string BLUE = "\x1B[34m";
    const std::string CYAN = "\x1B[36m";
    const std::string RESET = "\x1B[0m";
    Node();
    Node(std::string name, bool synchronous, std::string type, Node *parent);
    virtual ~Node();
    std::string getName();
    void setName(std::string name);
    double getLastModified();
    std::string timeToString(double time);
    bool isSynchronous();
    std::string getType();
    virtual IteratorManager *createIteratorManager() = 0;
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
    virtual State *getState() = 0;
    virtual void setState(State *state) = 0;
    void notify();

protected:
    std::string name;
    double lastModified;
    bool synchronous;
    std::string type;
    Node *parent;
    bool visited;
    Observer* observer;
};
#endif