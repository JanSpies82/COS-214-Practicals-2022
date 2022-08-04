#include "SquadMember.h"
using namespace std;
//TODO takeDamage() return bool or int?
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
SquadMember *SquadMember::clone()
{
return NULL;
};
