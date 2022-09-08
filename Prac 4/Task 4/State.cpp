#include "State.h"
using namespace std;

State::State(Node *n)
{
    name = n->getName();
    lastModified = n->getLastModified();
    synchronous = n->isSynchronous();
}

State::~State()
{
}
