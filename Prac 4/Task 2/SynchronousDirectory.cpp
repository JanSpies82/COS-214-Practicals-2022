#include "SynchronousDirectory.h"

using namespace std;

SynchronousDirectory::SynchronousDirectory(string name) : Directory(name, true)
{
}

SynchronousDirectory::~SynchronousDirectory()
{
    for (int i = 0; i < children->size(); i++)
    {
        delete children->at(i);
    }
    delete children;
}

void SynchronousDirectory::addChild(Node *child)
{
    if ((child->getType() != "File") && (!child->isSynchronous() && child->getType() != "Directory"))
        __throw_invalid_argument("Cannot add an asynchronous node to a synchronous directory");
    Directory::addChild(child);
}

Node *SynchronousDirectory::access(string name)
{
    for (int i = 0; i < children->size(); i++)
    {
        if (children->at(i)->getName() == name)
        {
            return children->at(i);
        }
    }
    throw invalid_argument("No child with name " + name + " found");
}