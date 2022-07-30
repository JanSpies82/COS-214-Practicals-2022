#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "User.h"
#include <vector>
class UserManager
{
private:
    User *User_;
    std::vector<AuditableSnapshot *>* history_;

public:
    UserManager(User *User);
    ~UserManager();
    void Backup();
    void Undo();
    void ShowHistory() const;
};
#endif // USERMANAGER_H