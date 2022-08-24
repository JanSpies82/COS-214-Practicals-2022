#ifndef BASKET_H
#define BASKET_H
#include <vector>
#include "Confectionary.h"

class Basket : public Confectionary
{
public:
    Basket();
    ~Basket();
    void add(Confectionary *);
    Confectionary *getConfectionary(int);

private:
    std::vector<Confectionary *> *confectionaries;
};
#endif