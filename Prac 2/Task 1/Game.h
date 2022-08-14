#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
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
    void run();

private:
    EnemyFactory **enemyFactories;
    SquadMember **squadMembers;
    const static std::string title;
};
#endif // GAME_H