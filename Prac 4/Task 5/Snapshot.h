#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <string>
#include "State.h"
class Snapshot
{
public:
    Snapshot(State *state);
    ~Snapshot();
    State *getState();

private:
    State *rootState;
    double lastModified;
};
#endif