#include "Observer.h"
#include "Node.h"
using namespace std;

Observer::Observer(Node *n)
{
    state = n->getState();
}

Observer::~Observer()
{
    delete state;
}

