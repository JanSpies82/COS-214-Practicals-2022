#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#include "SquadMember.h"
class Enemy
{
public:
    Enemy(std::string name, int HP, int damage, std::string attackMove, std::string defendMove);
    virtual ~Enemy();
    void attack(SquadMember *z);
    virtual bool hitSquadMember(SquadMember *z) = 0;
    virtual void celebrate() = 0;
    virtual bool getHit(SquadMember *z) = 0;
    virtual void die() = 0;
    int takeDamage(int dmg);
    std::string getName();
    int getHP();
    int getDamage();
    std::string getAttackMove();
    std::string getDefendMove();
    std::string getType();
    void setHP(int HP);
    void setDamage(int damage);
    void setAttackMove(std::string attackMove);
    void setDefendMove(std::string defendMove);
    void setType(std::string t);
    virtual Enemy *clone() = 0;

protected:
    int HP;
    int damage;
    std::string attackMove;
    std::string defendMove;
    std::string name;
    std::string type;
};
#endif // ENEMY_H