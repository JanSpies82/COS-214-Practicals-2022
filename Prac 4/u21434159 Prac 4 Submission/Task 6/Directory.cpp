#include "Directory.h"
#include "DirectoryIteratorFactory.h"
#include "IteratorManager.h"
#include "DirectoryState.h"
using namespace std;

const std::string BLUE = "\x1B[34m";

Directory::Directory() : Node()
{
    children = new vector<Node *>();
}

Directory::Directory(string name, bool synchronous, Node *parent) : Node(name, synchronous, "Directory", parent)
{
    children = new vector<Node *>();
}

Directory::~Directory()
{
}

void Directory::addChild(Node *child)
{
    if (child == NULL)
        __throw_invalid_argument("Cannot add a null node");
    children->push_back(child);
    child->setParent(this);
    this->lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    notify();
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
            notify();
            return;
        }
    }
    throw invalid_argument("No child with name " + name + " found");
}

Node *Directory::getChild(int i)
{
    if (i > children->size() - 1)
        return NULL;
    return children->at(i);
}

int Directory::getChildrenCount()
{
    return children->size();
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

IteratorManager *Directory::createIteratorManager()
{
    IteratorManager *manager = new IteratorManager();
    manager->setNode(this);
    return manager;
}

void Directory::addDirectory(Directory *directory)
{
    this->addChild(directory);
}

string Directory::print(int depth)
{
    string out = "";
    string space = "   ", hyph = "-";
    for (int h = 0; h < depth; h++)
        out += space;
    out += this->getName() + ":\n";
    int d = depth + 1;
    for (int i = 0; i < children->size(); i++)
    {
        if (children->at(i)->print(depth) != "")
            out += children->at(i)->print(d);
    }
    return out;
}

void Directory::addFile(File *file)
{
    this->addChild((Node *)file);
}

void Directory::removeDirectory(std::string name)
{
    this->removeChild(name);
}

void Directory::removeFile(std::string name)
{
    this->removeChild(name);
}

bool Directory::listDirectory()
{
    bool hasDirectory = false;
    string out = "";
    for (int i = 0; i < children->size(); i++)
        if (children->at(i)->getType() == "Directory")
        {
            hasDirectory = true;
            out += children->at(i)->getName() + "\n";
        }
    if (out == "")
        out = BLUE + this->getName() + RESET + " contains no sub-directories\n";
    else
        out = BLUE + this->getName() + RESET + " sub-directories:\n" + out;
    cout << out;
    return hasDirectory;
}

bool Directory::listFile()
{
    bool hasFile = false;
    string out = "";
    for (int i = 0; i < children->size(); i++)
        if (children->at(i)->getType() == "File")
        {
            hasFile = true;
            out += children->at(i)->getName() + "\n";
        }
    if (out == "")
        out = BLUE + this->getName() + RESET + " contains no files\n";
    else
        out = BLUE + this->getName() + RESET + " files:\n" + out;
    cout << out;
    return hasFile;
}

bool Directory::isEmpty()
{
    return children->size() == 0;
}

void Directory::visit()
{
    this->visited = true;
}

void Directory::resetVisit()
{
    this->visited = false;
    for (int i = 0; i < children->size(); i++)
        children->at(i)->resetVisit();
}

bool Directory::isVisited()
{
    bool v = visited;
    for (int i = 0; i < children->size(); i++)
        v = v && children->at(i)->isVisited();
    return v;
}

State *Directory::getState()
{
    return new DirectoryState(this);
}

void Directory::removeAllChildren()
{
    while (children->size() > 0)
        removeChild(children->at(0)->getName());

    delete children;
    children = new vector<Node *>();
}