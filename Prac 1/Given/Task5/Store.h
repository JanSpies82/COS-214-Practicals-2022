#ifndef STORE_H
#define STORE_H 
#include <vector>
#include "AuditableSnapshot.h"
#include "User.h"
class Store
{
public:
    Store();
    ~Store();
    void Add(AuditableSnapshot *snapshot);
    AuditableSnapshot *Remove();
    void Print(User *user);

private:
    std::vector<AuditableSnapshot *>* _snapshots;
};
#endif // STORE_H