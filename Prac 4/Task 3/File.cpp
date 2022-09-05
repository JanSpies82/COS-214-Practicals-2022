#include "File.h"
#include "FileIteratorFactory.h"
#include "Directory.h"
using namespace std;

File::File() : Node()
{
    contents = "";
    extension = "";
}

File::File(string name) : Node(name, false, "File")
{
    contents = "";
    extension = determineExtension(name);
}

File::~File()
{
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

NodeIterator *File::createIterator()
{
    FileIteratorFactory *factory = new FileIteratorFactory();
    NodeIterator *n = factory->createIterator();
    delete factory;
    return n;
}

string File::print()
{
    return name + "\n";
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
