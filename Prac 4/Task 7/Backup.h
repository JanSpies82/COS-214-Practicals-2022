#ifndef BACKUP_H
#define BACKUP_H
#include <vector>
#include "Snapshot.h"

class Backup
{
public:
    Backup();
    ~Backup();
    void addSnapshot(Snapshot *snapshot);
    Snapshot *removeSnapshot();
    void clearAll();

private:
    std::vector<Snapshot *> *snapshots;
};
#endif