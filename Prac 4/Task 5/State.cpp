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

State::State()
{
}

void State::setName(string name)
{
    this->name = name;
}

void State::setLastModified(double lastModified)
{
    this->lastModified = lastModified;
}

void State::setSynchronous(bool synchronous)
{
    this->synchronous = synchronous;
}

string State::getName()
{
    return name;
}

double State::getLastModified()
{
    return lastModified;
}

bool State::isSynchronous()
{
    return synchronous;
}

string State::getType()
{
    return type;
}

