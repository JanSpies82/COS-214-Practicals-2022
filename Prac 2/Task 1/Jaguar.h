#ifndef JAGUAR_H
#define JAGUAR_H
#include "Enemy.h"
class Jaguar : public Enemy
{
public:
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
};
#endif // JAGUAR_H