#include "DirectoryState.h"
#include "Directory.h"
using namespace std;

DirectoryState::DirectoryState(Directory *n) : State(n)
{
    children = new vector<State*>();
    for (int t=0; t<n->getChildrenCount(); t++)
    {
        children->push_back(n->getChild(t)->getState()->clone());
    }
}

DirectoryState::DirectoryState()
{
    children = new vector<State*>();
}

DirectoryState::~DirectoryState()
{
    for (int t=0; t<children->size(); t++)
    {
        delete children->at(t);
    }
    delete children;
}

State *DirectoryState::clone()
{
    DirectoryState *s = new DirectoryState();
    s->children = new vector<State*>();
    for (int t=0; t<children->size(); t++)
    {
        s->children->push_back(children->at(t)->clone());
    }
    return s;
}

