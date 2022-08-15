#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
#include "SquadMember.h"
#include "CannibalFactory.h"
#include "JaguarFactory.h"
#include "SnakeFactory.h"
#include "GorillaFactory.h"
#include "Move.h"
#include "MoveHistory.h"


class Game
{
public:
    Game();
    ~Game();
    void newGame();
    void takeTurn();
    bool alive();
    void gameOver();

private:
    EnemyFactory **enemyFactories;
    SquadMember **squadMembers;
    Enemy *currentEnemy;
    const static std::string title;
    void addHead();
    bool validInp(std::string in);
    int score;
    bool active;
    MoveHistory *moveHistory;
};
#endif // GAME_H