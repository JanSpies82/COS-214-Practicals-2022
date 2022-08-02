#ifndef SNAKE_H
#define SNAKE_H
#include "Enemy.h"
class Snake : public Enemy
{
public:
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
};
#endif // SNAKE_H