#ifndef MOVE_H
#define MOVE_H
#include "Game.h"
class Move
{
private:
    Move(int choice);
    ~Move();
    int getMove();
    int choice;
    friend class Game;
};
#endif // MOVE_H