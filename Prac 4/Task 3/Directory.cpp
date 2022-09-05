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
            out +=children->at(i)->print(d);
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
    for (int i = 0; i < children->size(); i++)
        if (children->at(i)->getType() == "Directory")
            hasDirectory = true;
    return hasDirectory;
}

bool Directory::listFile()
{
    bool hasFile = false;
    for (int i = 0; i < children->size(); i++)
        if (children->at(i)->getType() == "File")
            hasFile = true;
    return hasFile;
}

bool Directory::isEmpty()
{
    return children->size() == 0;
}
