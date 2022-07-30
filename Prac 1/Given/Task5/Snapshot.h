#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include "AuditableSnapshot.h"
class Snapshot : public AuditableSnapshot
{
public:
    Snapshot(std::string username, std::string date, std::string state);
    // ~Snapshot();
    std::string GetUsername() const override;
    std::string date() const override;
    std::string state() const override;

private:
    std::string _username;
    std::string _date;
    std::string _state;
};

#endif // SNAPSHOT_H