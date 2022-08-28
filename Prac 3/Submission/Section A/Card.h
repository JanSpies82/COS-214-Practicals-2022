#ifndef CARD_H
#define CARD_H
#include "AddOn.h"

class Card : public AddOn
{
public:
    Card(std::string message, Component *component);
    ~Card();
    bool isDiscountable();
    std::string getDescription();
    bool hasNote();
    bool hasCard();
    double getPrice();

protected:
    std::string message;
};
#endif // CARD_H