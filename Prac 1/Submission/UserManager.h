#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "User.h"
#include "Store.h"
class UserManager
{
private:
    User *User_;
    Store *Store_;

public:
    UserManager(User *User);
    ~UserManager();
    void Backup();
    void Undo();
    void ShowHistory() const;
};
#endif // USERMANAGER_H