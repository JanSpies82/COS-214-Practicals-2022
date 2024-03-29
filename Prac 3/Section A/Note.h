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
    bool hasNote();
    bool hasCard();
    double getPrice();

protected:
    std::string message;
};
#endif