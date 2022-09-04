#include "AsynchronousDirectory.h"
using namespace std;
AsynchronousDirectory::AsynchronousDirectory(string name) : Directory(name, false)
{
}

AsynchronousDirectory::~AsynchronousDirectory()
{
    for (int i = 0; i < children->size(); i++)
    {
        delete children->at(i);
    }
    delete children;
}

void AsynchronousDirectory::addChild(Node *child)
{
    if ((child->getType() != "File") && (child->isSynchronous()))
        __throw_invalid_argument("Cannot add a synchronous node to an asynchronous directory");
    Directory::addChild(child);
}

Node *AsynchronousDirectory::access(string name)
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