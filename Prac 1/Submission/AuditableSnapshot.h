#ifndef AUDITABLESNAPSHOT_H
#define AUDITABLESNAPSHOT_H
#include <string>
class AuditableSnapshot
{
protected:
    virtual std::string GetUsername() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
    std::string _username;
    std::string _date;
    std::string _state;
    friend class User;
};
#endif // AUDITABLESNAPSHOT_H