#include "CheckPoint.h"
using namespace std;

CheckPoint::CheckPoint(SquadMember **sq, int score)
{
    squad = new SquadMember *[2];
    for (int i = 0; i < 2; i++)
    {
        squad[i] = new SquadMember(sq[i]->getName());
        squad[i]->setHP(sq[i]->getHP());
        squad[i]->setDamage(sq[i]->getDamage());
    }
    this->score = score;
}

CheckPoint::~CheckPoint()
{
    for (int i = 0; i < 2; i++)
    {
        delete squad[i];
    }
    delete[] squad;
}

SquadMember **CheckPoint::getSquadMembers()
{
    return squad;
};
int CheckPoint::getScore()
{
    return score;
};