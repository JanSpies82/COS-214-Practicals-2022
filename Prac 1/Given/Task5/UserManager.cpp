#include "UserManager.h"

UserManager::UserManager(User *User) : User_(User)
{
  ;
  //? Implemented
  history_ = new std::vector<AuditableSnapshot *>();
}

UserManager::~UserManager()
{
  //? Implemented
  for (int i = 0; i < history_->size(); i++)
  {
    delete history_->at(i);
  }
  delete history_;
  // if (User_ != NULL)
  // {
  //   delete User_;
  // }
}

void UserManager::Backup()
{
  std::cout << "\nUserManager: Saving User's state...\n";
  //? Implemented
  history_->push_back(User_->Save());
}

void UserManager::Undo()
{
  //? Implemented
  if (history_->size() > 0)
  {
    AuditableSnapshot *snapshot = history_->back();
    User_->Restore(snapshot);
    history_->pop_back();
    delete snapshot;
  }
}

void UserManager::ShowHistory() const
{
  std::cout << "UserManager: Here's the list of historal changes:\n";
  //? Implemented
  for (int i = history_->size() - 1; i >= 0; i--)
  {
    AuditableSnapshot *snapshot = history_->at(i);
    std::cout << snapshot->date() << ": " << snapshot->GetUsername() << " - " << snapshot->state() << "\n";
  }
}
