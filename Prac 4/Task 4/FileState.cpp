#include "FileState.h"
#include "File.h"
using namespace std;

FileState::FileState(File *n) : State(n)
{
    File *f = (File*)n;
    contents = f->getContents();
    extension = f->getExtension();
}

FileState::FileState()
{
}

FileState::~FileState()
{
}

State *FileState::clone()
{
    FileState *s = new FileState();
    s->contents = contents;
    s->extension = extension;
    return s;
}
