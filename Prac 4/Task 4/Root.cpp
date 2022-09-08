#include "Root.h"
#include "Backup.h"
#include "DirectoryState.h"
#include "SynchronousDirectory.h"
#include "AsynchronousDirectory.h"
#include "File.h"
using namespace std;

Root::Root() : Directory("root", true)
{
    backup = new Backup();
}

Root::~Root()
{
    delete backup;
}

void Root::createSnapshot()
{
    Snapshot *s = new Snapshot(getState());
    backup->addSnapshot(s);
}

void Root::restoreSnapshot()
{
    Snapshot *s = backup->removeSnapshot();
    setState(s->getState());
    delete s;
}

void Root::clearAll()
{
    backup->clearAll();
}

void Root::addChild(Node *child)
{
    Directory::addChild(child);
}

Node *Root::access(std::string name)
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

State *Root::getState()
{
    return Directory::getState();
};

void Root::setState(State *state)
{
    DirectoryState *directoryState = (DirectoryState *)state;
    this->name = directoryState->getName();
    this->synchronous = directoryState->isSynchronous();
    this->lastModified = directoryState->getLastModified();
    this->removeAllChildren();
    for (int i = 0; i < directoryState->children->size(); i++)
    {
        string s = directoryState->children->at(i)->getType();
        if (s == "Synchronous Directory")
        {
            SynchronousDirectory *d = new SynchronousDirectory(directoryState->children->at(i)->getName());
            d->setState(directoryState->children->at(i));
            this->addChild(d);
        }
        else if (s == "Asynchronous Directory")
        {
            AsynchronousDirectory *d = new AsynchronousDirectory(directoryState->children->at(i)->getName());
            d->setState(directoryState->children->at(i));
            this->addChild(d);
        }
        else if (s == "File")
        {
            File *f = new File(directoryState->children->at(i)->getName());
            f->setState(directoryState->children->at(i));
            this->addChild(f);
        }
    }
};