#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "SquadMember.h"
class Enemy
{
public:
    Enemy();
    ~Enemy();
    virtual void attack(Enemy* z);
    virtual bool hitSquadMember(Enemy* z);
    virtual void celebrate();
    virtual bool getHit(Enemy* z);
    virtual void die(); 

    int HP;
    int damage;
    std::string attackMove;
    std::string defendMove
};
#endif // ENEMY_H