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
    void clearAll();
    void addChild(Node *child);
    Node *access(std::string name);
    State *getState();
    void setState(State *state);

private:
    Backup *backup;
};
#endif