#ifndef CHECKPOINT_H
#define CHECKPOINT_H
#include "Enemy.h"
#include "SquadMember.h"
class CheckPoint
{
public:
    CheckPoint(SquadMember **sq, int score);
    ~CheckPoint();

private:
    SquadMember **getSquadMembers();
    int getScore();
    int score;
    SquadMember **squad;
    friend class Game;
};
#endif // CHECKPOINT_H