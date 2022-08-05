#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#include "SquadMember.h"
//TODO add subclass constructors and main
class Enemy
{
public:
    Enemy(std::string name, int HP, int damage, std::string attackMove, std::string defendMove);
    // virtual ~Enemy();
    void attack(SquadMember* z);
    virtual bool hitSquadMember(SquadMember* z)=0;
    virtual void celebrate()=0;
    virtual bool getHit(SquadMember* z)=0;
    virtual void die()=0; 
    int takeDamage(int dmg);
    std::string getName();
    int getHP();
    int getDamage();
    std::string getAttackMove();
    std::string getDefendMove();

    int HP;
    int damage;
    std::string attackMove;
    std::string defendMove;
    std::string name;
};
#endif // ENEMY_H