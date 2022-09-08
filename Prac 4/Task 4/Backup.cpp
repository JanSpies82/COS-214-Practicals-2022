#include "Backup.h"
using namespace std;

Backup::Backup()
{
    snapshots = new vector<Snapshot *>();
}

Backup::~Backup()
{
    clearAll();
    delete snapshots;
}

void Backup::addSnapshot(Snapshot *snapshot)
{
    snapshots->push_back(snapshot);
}

Snapshot *Backup::removeSnapshot()
{
    Snapshot *snapshot = snapshots->back();
    snapshots->pop_back();
    return snapshot;
}       

void Backup::clearAll()
{
    while (!snapshots->empty())
    {
        delete removeSnapshot();
    }
}
