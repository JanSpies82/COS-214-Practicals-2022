#ifndef AUDITABLESNAPSHOT_H
#define AUDITABLESNAPSHOT_H
#include <string>
class AuditableSnapshot
{
public:
    virtual std::string GetUsername() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
};
#endif // AUDITABLESNAPSHOT_H