#include "UserManager.h"

UserManager::UserManager(User *User) : User_(User)
{
  ;
  //? Implemented
  Store_ = new Store();
}

UserManager::~UserManager()
{
  //? Implemented
  delete Store_;
}

void UserManager::Backup()
{
  std::cout << "\nUserManager: Saving User's state...\n";
  //? Implemented
  Store_->Add(User_->Save());
}

void UserManager::Undo()
{
  //? Implemented
  User_->Restore(Store_->Remove());
}

void UserManager::ShowHistory() const
{
  std::cout << "UserManager: Here's the list of historal changes:\n";
  //? Implemented
  Store_->Print(User_);
}
