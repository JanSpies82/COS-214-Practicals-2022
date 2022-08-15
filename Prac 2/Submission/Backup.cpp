#include "Backup.h"
using namespace std;

Backup::Backup()
{
    checkpoints = new vector<CheckPoint *>();
}

Backup::~Backup()
{
    for (int i = 0; i < checkpoints->size(); i++)
    {
        delete checkpoints->at(i);
    }
    delete checkpoints;
}

void Backup::addCheckpoint(CheckPoint *c)
{
    checkpoints->push_back(c);
}

CheckPoint *Backup::getCheckPoint()
{
    if (checkpoints->size() > 0)
    {
        CheckPoint *c = checkpoints->back();
        checkpoints->pop_back();
        return c;
    }
    return NULL;
}
