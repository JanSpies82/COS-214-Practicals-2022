#ifndef STATE_H
#define STATE_H
#include "Node.h"

class DirectoryState;
class State
{
    friend class Node;
    friend class Directory;
    friend class SynchronousDirectory;
    friend class AsynchronousDirectory;
    friend class Root;
    friend class File;
    friend class Antivirus;

    friend class DirectoryState;

public:
    virtual ~State();
    virtual State *clone() = 0;
    State(Node *n);
    State();

protected:
    void setName(std::string name);
    void setLastModified(double lastModified);
    void setSynchronous(bool synchronous);
    std::string getName();
    double getLastModified();
    bool isSynchronous();
    std::string getType();
    virtual int numChildren()=0;
    DirectoryState* getParent();
    std::string name;
    double lastModified;
    bool synchronous;
    std::string type;
    DirectoryState* parent;
};
#endif