#ifndef STATE_H
#define STATE_H
#include "Node.h"

class State
{
    friend class Node;

public:
    ~State();
    virtual State *clone()=0;

protected:
    State(Node *n);
    State();
    void setName(std::string name);
    void setLastModified(double lastModified);
    void setSynchronous(bool synchronous);
    std::string getName();
    double getLastModified();
    bool isSynchronous();
    std::string name;
    double lastModified;
    bool synchronous;
};
#endif