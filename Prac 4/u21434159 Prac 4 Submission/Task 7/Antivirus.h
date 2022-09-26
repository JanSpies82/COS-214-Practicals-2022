#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H
#include "Observer.h"
class Root;
class Antivirus : public Observer
{
public:
    Antivirus(Root *r);
    ~Antivirus();
    void update();

protected:
    Root *subject;
};
#endif
