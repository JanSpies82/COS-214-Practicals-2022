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
    dead = (HP <= 0);
};
void SquadMember::setDamage(int dmg)
{
    if (dmg >= 0)
        damage = dmg;
};
int SquadMember::takeDamage(int dmg)
{
    HP -= dmg;
    if (HP <= 0)
    {
        die();
    }
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
    srand(time(0));
    int index = rand() % 5;
    return names[index];
};
void SquadMember::print()
{
    if (!isDead())
        cout << setw(10) << left << name << ": " << setw(2) << left << HP << " HP, " << setw(2) << left << damage << " damage" << endl;
    else
        cout << setw(10) << left << name << ": DEAD" << endl;
};

SquadMember *SquadMember::clone()
{
    SquadMember *newMember = new SquadMember();
    newMember->setDamage(this->getDamage());
    newMember->setHP(this->getHP());
    return newMember;
};
