#include "Root.h"
using namespace std;

Root::Root() : Directory("root", true)
{
    // backup = new Backup();
}

Root::~Root()
{
    // delete backup;
}

void Root::createSnapshot()
{
    // backup->createSnapshot(this);
}

void Root::restoreSnapshot()
{
    // backup->restoreSnapshot(this);
}

void Root::listBackup()
{
    // backup->listBackup();
}

void Root::deleteSnapshot()
{
    // backup->deleteSnapshot();
}

void Root::clearAll()
{
    // backup->clearAll();
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