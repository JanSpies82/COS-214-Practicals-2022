#include "Move.h"
#include <iostream>
using namespace std;

Move::Move(SquadMember **sq, Enemy *e, int score)
{
    squad = new SquadMember *[2];
    for (int i = 0; i < 2; i++)
    {
        squad[i] = new SquadMember(sq[i]->getName());
        squad[i]->setHP(sq[i]->getHP());
        squad[i]->setDamage(sq[i]->getDamage());
    }
    enemy = e->clone();
    this->score = score;
};

Move::~Move()
{
    delete enemy;
    for (int i = 0; i < 2; i++)
    {
        delete squad[i];
    }
    delete[] squad;
};
SquadMember **Move::getSquadMembers()
{
    return squad;
};
Enemy *Move::getEnemy()
{
    return enemy;
};
int Move::getScore()
{
    return score;
};