#ifndef GORILLA_H
#define GORILLA_H
#include "Enemy.h"
class Gorilla : public Enemy
{
public:
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
};
#endif // GORILLA_H