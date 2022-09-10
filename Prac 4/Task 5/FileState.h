#ifndef FILESTATE_H
#define FILESTATE_H
#include "State.h"

class FileState : public State
{
    friend class File;

public:
    ~FileState();
    State *clone();

protected:
    FileState(File *n);
    FileState();
    std::string contents;
    std::string extension;
    int numChildren();
};
#endif