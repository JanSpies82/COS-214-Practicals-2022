#ifndef JAGUAR_H
#define JAGUAR_H
#include "Enemy.h"
class Jaguar : public Enemy
{
public:
    bool hitSquadMember(Enemy *z);
    void celebrate();
    bool getHit(Enemy *z);
    void die();
};
#endif // JAGUAR_H