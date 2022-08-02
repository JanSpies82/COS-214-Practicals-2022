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
    void attack(SquadMember* z);
    virtual bool hitSquadMember(SquadMember* z);
    virtual void celebrate();
    virtual bool getHit(SquadMember* z);
    virtual void die(); 
    int takeDamage(int dmg);
    std::string getName();
    int getHP();
    int getDamage();
    std::string getAttackMove();
    std::string getDefendMove();

private:
    int HP;
    int damage;
    std::string attackMove;
    std::string defendMove;
    std::string name;
};
#endif // ENEMY_H