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

public:
    ~DirectoryState();
    State *clone();

protected:
    DirectoryState(Directory *n);
    DirectoryState();
    std::vector<State *> *children;
};
#endif