#ifndef SQUADMEMBER_H
#define SQUADMEMBER_H
#include <string>
#include <iostream>
#include <iomanip>
class SquadMember
{
public:
    SquadMember();
    SquadMember(std::string name);
    std::string getName();
    int getHP();
    int getDamage();
    void setHP(int hp);
    void setDamage(int dmg);
    int takeDamage(int dmg);
    bool isDead();
    void die();
    void print();
    SquadMember *clone();

private:
    std::string name;
    int HP;
    int damage;
    bool dead;
    const static std::string names[];
    std::string generateName();
};
#endif