#include "Move.h"
#include <iostream>
using namespace std;

Move::Move(SquadMember **sq, Enemy *e)
{
    squad = new SquadMember *[2];
    for (int i = 0; i < 2; i++)
    {
        squad[i] = new SquadMember(sq[i]->getName());
        squad[i]->setHP(sq[i]->getHP());
        squad[i]->setDamage(sq[i]->getDamage());
    }
    enemy = e->clone();
};

Move::~Move()
{
    delete enemy;
    cout << "Deleted enemy\n";
    for (int i = 0; i < 2; i++)
    {
        delete squad[i];
        cout << "Deleted squadmember\n";
    }
    delete[] squad;
    cout << "Deleted squad\n";
};
SquadMember **Move::getSquadMembers()
{
    return squad;
};
Enemy *Move::getEnemy()
{
    return enemy;
};