#include "SynchronousDirectory.h"
#include "DirectoryState.h"
#include "File.h"
#include "AsynchronousDirectory.h"
#include "DirectoryObserver.h"

using namespace std;

SynchronousDirectory::SynchronousDirectory(string name) : Directory(name, true)
{
    observer = new DirectoryObserver(this);
}

SynchronousDirectory::~SynchronousDirectory()
{
    for (int i = 0; i < children->size(); i++)
    {
        delete children->at(i);
    }
    delete children;
    delete observer;
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

void SynchronousDirectory::addDirectory(Directory *directory)
{
    Directory::addDirectory(directory);
}

void SynchronousDirectory::addFile(File *file)
{
    Directory::addFile(file);
}

void SynchronousDirectory::removeDirectory(string name)
{
    Directory::removeDirectory(name);
}

void SynchronousDirectory::removeFile(string name)
{
    Directory::removeFile(name);
}

bool SynchronousDirectory::listDirectory()
{
    return Directory::listDirectory();
}

bool SynchronousDirectory::listFile()
{
    return Directory::listFile();
}

bool SynchronousDirectory::isEmpty()
{
    return Directory::isEmpty();
}

void SynchronousDirectory::setState(State *state)
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
}