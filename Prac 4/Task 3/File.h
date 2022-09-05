#ifndef FILE_H
#define FILE_H
#include "Node.h"

class File : public Node
{
public:
    friend class FileIterator;
    File();
    File(std::string name, Node *parent = NULL);
    ~File();
    std::string getContents();
    void setContents(std::string contents);
    std::string getExtension();
    void setExtension(std::string extension);
    void appendContents(std::string contents);
    void prependContents(std::string contents);
    void setName(std::string name);
    NodeIterator *createIterator();
    std::string print(int depth = 0);
    virtual void addDirectory(Directory *directory);
    virtual void addFile(File *file);
    virtual void removeDirectory(std::string name);
    virtual void removeFile(std::string name);
    virtual bool listDirectory();
    virtual bool listFile();
    virtual bool isEmpty();

private:
    std::string contents;
    std::string extension;
    std::string determineExtension(std::string name);
};
#endif