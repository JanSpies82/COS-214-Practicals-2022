#ifndef GORILLA_H
#define GORILLA_H
#include "Enemy.h"
class Gorilla : public Enemy
{
public:
    bool hitSquadMember(Enemy *z);
    void celebrate();
    bool getHit(Enemy *z);
    void die();
};
#endif // GORILLA_H