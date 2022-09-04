#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include <vector>

class Directory : public Node
{
public:
    Directory();
    Directory(std::string name);
    virtual ~Directory();
    virtual void addChild(Node *child) = 0;
    Node *removeChild(std::string name);
    std::vector<Node *> *getChildren();
    std::string listContents();
    std::string getType();
    virtual Node *access(std::string name) = 0;

protected:
    std::string type;
    std::vector<Node *> *children;
};
#endif