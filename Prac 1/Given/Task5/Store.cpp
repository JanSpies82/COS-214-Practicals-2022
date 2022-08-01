#include "Store.h"
Store::Store()
{
    _snapshots = new std::vector<AuditableSnapshot *>();
};
Store::~Store()
{
    for (int i = 0; i < _snapshots->size(); i++)
    {
        delete _snapshots->at(i);
    }
    delete _snapshots;
};

void Store::Add(AuditableSnapshot *snapshot)
{
    _snapshots->push_back(snapshot);
};

AuditableSnapshot *Store::Remove()
{
    if (_snapshots->size() > 0)
    {
        AuditableSnapshot *snapshot = _snapshots->back();
        _snapshots->pop_back();
        return snapshot;
    }
};
void Store::Print(User *user)
{
    for (int i = _snapshots->size() - 1; i >= 0; i--)
    {
        user->Print(_snapshots->at(i));
    }
};