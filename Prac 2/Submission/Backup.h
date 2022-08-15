#ifndef BACKUP_H
#define BACKUP_H
#include "CheckPoint.h"
#include <vector>
class Backup
{
public:
    Backup();
    ~Backup();
    void addCheckpoint(CheckPoint* c);
    CheckPoint* getCheckPoint();

private:
    std::vector<CheckPoint *>* checkpoints;
};
#endif // BACKUP_H