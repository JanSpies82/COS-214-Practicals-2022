#ifndef BASKET_H
#define BASKET_H
#include <vector>
#include "Component.h"
#include "Confectionary.h"

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

private:
    std::vector<Confectionary *> *confectionaries;
};
#endif