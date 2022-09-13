#ifndef OBSERVER_H
#define OBSERVER_H
#include "State.h"
#include <iostream>
class Node;
class Observer
{
public:
    Observer(Node *n);
    virtual ~Observer();
    virtual void update() = 0;

protected:
    State *state;
};
#endif