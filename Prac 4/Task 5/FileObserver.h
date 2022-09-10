#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H
#include "Observer.h"
class File;
class FileObserver : public Observer
{
public:
    FileObserver(File *f);
    ~FileObserver();
    void update();

protected:
    File *subject;
};
#endif