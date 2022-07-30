#include "User.h"

  std::string User::GenerateRandomString(int length)
  {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < length; i++)
    {
      random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
  }


  User::User(std::string username, std::string password) : _username(username), _password(password)
  {
    std::cout << "User: I have been initialized with username " << this->_username << " and a password of " << this->_password << "\n";
  }

  void User::SetPassword()
  {
    std::cout << "User: Setting a new secure password.\n";
    //? Implemented
    this->_password = GenerateRandomString();
    std::cout << "User: My password has been changed to: " << this->_password << "\n";
  }

  void User::SetPassword(std::string password){
    this->_password = password;
    std::cout << "User: My password has been changed to: " << this->_password << "\n";
  }

  AuditableSnapshot *User::Save()
  {
    //? Implemented
    // time_t rawtime;
    // struct tm *timeinfo;
    // char buffer[80];

    // time(&rawtime);
    // timeinfo = localtime(&rawtime);

    // strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    // std::string str(buffer);
    // std::string pass = this->_password;
    // delete timeinfo;
    return new Snapshot(this->_username, "str" , this->_password);
  }

  void User::Restore(AuditableSnapshot *memento)
  {
    this->_password = memento->state();
    std::cout << "User: My password has changed to: " << this->_password << "\n";
  }

