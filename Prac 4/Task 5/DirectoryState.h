#ifndef DIRECTORYSTATE_H
#define DIRECTORYSTATE_H
#include "State.h"
#include <vector>

class DirectoryState : public State
{
    friend class Directory;
    friend class SynchronousDirectory;
    friend class AsynchronousDirectory;
    friend class Root;
    friend class Antivirus;

public:
    ~DirectoryState();
    State *clone();

protected:
    DirectoryState(Directory *n);
    DirectoryState();
    int numChildren();
    std::vector<State *> *children;
};
#endif