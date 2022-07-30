#ifndef USER_H
#define USER_H
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "AuditableSnapshot.h"
#include "Snapshot.h"
class User
{
private:
    std::string _username;
    std::string _password;
    std::string GenerateRandomString(int length = 10);
public:
    User(std::string username, std::string password);
    void SetPassword();
    void SetPassword(std::string password);
    AuditableSnapshot *Save();
    void Restore(AuditableSnapshot *memento);
};

#endif // USER_H