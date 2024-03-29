#include "DirectoryObserver.h"
#include "Directory.h"
using namespace std;

DirectoryObserver::DirectoryObserver(Directory *d) : Observer(d)
{
    subject = d;
}

DirectoryObserver::~DirectoryObserver()
{
}

void DirectoryObserver::update()
{
    // cout << "DirectoryObserver: The subject " << subject->getName() << " has been updated." << endl;
    delete state;
    state = subject->getState();
    if (subject->getParent() != NULL)
        subject->getParent()->notify();
}