#include "FileObserver.h"
#include "File.h"
using namespace std;

FileObserver::FileObserver(File *f) : Observer(f)
{
    subject = f;
}

FileObserver::~FileObserver()
{
}

void FileObserver::update()
{
    cout << "FileObserver: The subject " << subject->getName() << " has been updated." << endl;
    if (subject->getParent() != NULL)
        subject->getParent()->notify();
}
