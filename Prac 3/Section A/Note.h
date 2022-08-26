#ifndef NOTE_H
#define NOTE_H
#include "AddOn.h"

class Note : public AddOn
{
public:
    Note(std::string message, Component *component);
    ~Note();
    bool isDiscountable();
    std::string getDescription();

protected:
    std::string message;
};
#endif