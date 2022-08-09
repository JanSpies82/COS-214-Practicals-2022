#include "SquadMember.h"
using namespace std;
const string SquadMember::names[] = {"Adam", "Bradley", "Charles", "David", "Edward"};

SquadMember::SquadMember()
{
    name = generateName();
    HP = 0;
    damage = 0;
};

SquadMember::SquadMember(std::string name)
{
    this->name = name;
    HP = 0;
    damage = 0;
};

std::string SquadMember::getName()
{
    return name;
};
int SquadMember::getHP()
{
    return HP;
};
int SquadMember::getDamage()
{
    return damage;
};
void SquadMember::setHP(int hp)
{
    HP = hp;
};
void SquadMember::setDamage(int dmg)
{
    damage = dmg;
};
int SquadMember::takeDamage(int dmg)
{
    HP -= dmg;
    return HP;
}
bool SquadMember::isDead()
{
    return dead;
};
void SquadMember::die()
{
    dead = true;
    HP = 0;
};
string SquadMember::generateName()
{
    int index = rand() % 5;
    return names[index];
};
SquadMember *SquadMember::clone()
{
    SquadMember *newMember = new SquadMember();
    newMember->setDamage(this->getDamage());
    newMember->setHP(this->getHP());
    return newMember;
};
