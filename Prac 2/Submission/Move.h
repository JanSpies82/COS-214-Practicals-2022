#ifndef MOVE_H
#define MOVE_H
#include "Enemy.h"
#include "SquadMember.h"
class Move
{
public:
    Move(SquadMember **sq, Enemy *e, int score);
    ~Move();

private:
    SquadMember **getSquadMembers();
    Enemy *getEnemy();
    int getScore();
    int score;
    SquadMember **squad;
    Enemy *enemy;
    friend class Game;
};
#endif // MOVE_H