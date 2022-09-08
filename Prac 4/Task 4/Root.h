#ifndef ROOT_H
#define ROOT_H
#include "Directory.h"

class Backup;
class Root : public Directory
{
public:
    Root();
    ~Root();
    void createSnapshot();
    void restoreSnapshot();
    void listBackup();
    void deleteSnapshot();
    void clearAll();
    void addChild(Node *child);
   Node *access(std::string name);

private:
    Backup *backup;
};
#endif