#ifndef FILE_H
#define FILE_H
#include "Node.h"

class File : public Node
{
public:
    File();
    File(std::string name);
    ~File();
    std::string getContents();
    void setContents(std::string contents);
    std::string getExtension();
    void setExtension(std::string extension);
    void appendContents(std::string contents);
    void prependContents(std::string contents);
    void setName(std::string name);

private:
    std::string contents;
    std::string extension;
    std::string determineExtension(std::string name);
};
#endif