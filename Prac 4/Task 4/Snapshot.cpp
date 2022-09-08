#include "Snapshot.h"
using namespace std;

Snapshot::Snapshot(State* state)
{
    rootState = state;
}

Snapshot::~Snapshot()
{
    delete rootState;
}

State* Snapshot::getState()
{
    return rootState;
}

