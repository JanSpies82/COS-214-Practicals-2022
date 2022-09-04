#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include <vector>

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

protected:
    std::vector<Node *> *children;
};
#endif