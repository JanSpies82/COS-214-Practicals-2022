#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include "Pokemon.h"

class Game
{
public:
    Game();
    ~Game();
    void newGame();
    bool takeTurn();
    void addHead();
    void gameOver();

private:
    std::vector<Pokemon *> *allPokemon;
    Pokemon **team;
    Pokemon **enemies;
    int teamSize;
    int score;
    int enemyIndex;
    bool active;
    const static std::string title;
    bool isAlive();
};
#endif