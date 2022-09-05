#include "Directory.h"
#include "DirectoryIteratorFactory.h"
using namespace std;

Directory::Directory() : Node()
{
    children = new vector<Node *>();
}

Directory::Directory(string name, bool synchronous) : Node(name, synchronous, "Directory")
{
    children = new vector<Node *>();
}

Directory::~Directory()
{
    for (int i = 0; i < children->size(); i++)
    {
        delete children->at(i);
    }
    delete children;
}

void Directory::addChild(Node *child)
{
    children->push_back(child);
    this->lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

void Directory::removeChild(string name)
{
    for (int i = 0; i < children->size(); i++)
    {
        if (children->at(i)->getName() == name)
        {
            Node *child = children->at(i);
            children->erase(children->begin() + i);
            this->lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
            delete child;
            return;
        }
    }
    throw invalid_argument("No child with name " + name + " found");
}

vector<Node *> *Directory::getChildren()
{
    return children;
}

string Directory::listContents()
{
    string contents = "";
    for (int i = 0; i < children->size(); i++)
    {
        contents += children->at(i)->getName() + "\n";
    }
    return contents;
}

NodeIterator *Directory::createIterator()
{
    DirectoryIteratorFactory *factory = new DirectoryIteratorFactory();
    NodeIterator *n = factory->createIterator();
    delete factory;
    return n;
}
