#ifndef BASKET_H
#define BASKET_H
#include <vector>
#include "Component.h"
class Confectionary;

class Basket : public Component
{
public:
    Basket();
    ~Basket();
    void add(Confectionary *c);
    Confectionary *getConfectionary(int i);
    std::string getDescription();
    int getSize();
    double getPrice();
    std::string getType();
    void setPrice(double price);
    void setType(std::string type);
    bool canAddDiscount();
    bool isDiscountable();
    void setDiscount(double discount);

private:
    std::vector<Confectionary *> *confectionaries;
    double price;
    std::string type;
};
#endif