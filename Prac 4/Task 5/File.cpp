#include "File.h"
#include "FileIteratorFactory.h"
#include "Directory.h"
#include "IteratorManager.h"
#include "FileState.h"
#include "FileObserver.h"
using namespace std;

File::File() : Node()
{
    contents = "";
    extension = "";
}

File::File(string name, Node *parent) : Node(name, false, "File", parent)
{
    contents = "";
    extension = determineExtension(name);
    observer = new FileObserver(this);
}

File::~File()
{
    delete observer;
}

void File::setName(string name)
{
    Node::setName(name);
    extension = determineExtension(name);
}

string File::getContents()
{
    return contents;
}

void File::setContents(string contents)
{
    this->contents = contents;
}

string File::getExtension()
{
    return extension;
}

void File::setExtension(string extension)
{
    this->extension = extension;
    int index = name.find_last_of(".");
    if (index != string::npos)
    {
        name = name.substr(0, index);
    }
    if (extension != "")
        name += "." + extension;
}

void File::appendContents(string contents)
{
    this->contents += contents;
}

void File::prependContents(string contents)
{
    this->contents = contents + this->contents;
}

string File::determineExtension(string name)
{
    int index = name.find_last_of(".");
    if (index != string::npos)
    {
        return name.substr(index + 1);
    }
    return "";
}

IteratorManager *File::createIteratorManager()
{
    IteratorManager *manager = new IteratorManager();
    manager->setNode(this);
    return manager;
}

string File::print(int depth)
{
    string out = "";
    string space = "   ", hyph = "-";
    for (int h = 0; h < depth; h++)
        out += space;
    out += hyph + this->getName() + "\n";
    return out;
}

void File::addDirectory(Directory *directory)
{
    __throw_logic_error("Cannot add directory to file");
}

void File::addFile(File *file)
{
    __throw_logic_error("Cannot add file to file");
}

void File::removeDirectory(std::string name)
{
    __throw_logic_error("Cannot remove directory from file");
}

void File::removeFile(std::string name)
{
    __throw_logic_error("Cannot remove file from file");
}

bool File::listDirectory()
{
    return true;
}

bool File::listFile()
{
    return false;
}

bool File::isEmpty()
{
    return true;
}

void File::visit()
{
    visited = true;
}

void File::resetVisit()
{
    visited = false;
}

State *File::getState()
{
    return new FileState(this);
}

void File::setState(State *state)
{
    FileState *s = (FileState*)state;
    contents = s->contents;
    extension = s->extension;
}