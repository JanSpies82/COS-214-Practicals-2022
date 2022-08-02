#ifndef CANNIBAL_H
#define CANNIBAL_H
#include "Enemy.h"
class Cannibal : public Enemy
{
public:
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
};
#endif // CANNIBAL_H