#ifndef DIRECTORYOBSERVER_H
#define DIRECTORYOBSERVER_H
#include "Observer.h"
class Directory;
class DirectoryObserver : public Observer
{
public:
    DirectoryObserver(Directory *d);
    ~DirectoryObserver();
    void update();

protected:
    Directory *subject;
};
#endif