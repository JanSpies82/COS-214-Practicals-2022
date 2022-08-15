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

class Game
{
public:
    Game();
    ~Game();
    void newGame();
    void takeTurn();
    bool alive();
    void gameOver(std::string message = "All squadmembers have died!");

private:
    EnemyFactory **enemyFactories;
    SquadMember **squadMembers;
    const static std::string title;
    void addHead();
    bool validInp(std::string in);
    int score;
    bool active;
};
#endif // GAME_H