#include "Directory.h"

using namespace std;

Directory::Directory() : Node()
{
    children = new vector<Node *>();
}

Directory::Directory(string name) : Node(name)
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
}

Node *Directory::removeChild(string name)
{
    for (int i = 0; i < children->size(); i++)
    {
        if (children->at(i)->getName() == name)
        {
            Node *child = children->at(i);
            children->erase(children->begin() + i);
            return child;
        }
    }
    return NULL;
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

string Directory::getType()
{
    return type;
}

