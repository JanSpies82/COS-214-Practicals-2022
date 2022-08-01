#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include "AuditableSnapshot.h"
class Snapshot : public AuditableSnapshot
{
private:
    Snapshot(std::string username, std::string date, std::string state);
    // ~Snapshot();
    std::string GetUsername() const override;
    std::string date() const override;
    std::string state() const override;
    std::string _username;
    std::string _date;
    std::string _state;
    friend class User;
};

#endif // SNAPSHOT_H