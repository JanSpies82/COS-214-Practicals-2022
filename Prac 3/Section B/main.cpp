#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Pokemon.h"

#include "NormalBattleState.h"
#include "AgileBattleState.h"
#include "StrongBattleState.h"

#include "AttackPlayStyle.h"
#include "RunPlayStyle.h"
#include "PhysicalPlayStyle.h"

#include "Game.h"

using namespace std;

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

void testStates()
{
    cout << CYAN << "Testing State changes" << RESET << endl;
    Pokemon *p = new Pokemon("Pikachu", 100, 10, new PhysicalPlayStyle());
    p->selectBattleState();
    p->selectBattleState();
    p->selectBattleState();
    p->selectBattleState();

    delete p;
}

void testStyles()
{
    Pokemon *p = new Pokemon("Pikachu", 100, 10, new AttackPlayStyle());
    cout << CYAN << "Attacking with AttackPlayStyle" << RESET << endl;
    p->attack();

    p->setStyle(new RunPlayStyle());
    cout << CYAN << "Attacking with RunPlayStyle" << RESET << endl;
    p->attack();

    p->setStyle(new PhysicalPlayStyle());
    cout << CYAN << "Attacking with PhysicalPlayStyle" << RESET << endl;
    p->attack();

    delete p;
}

void testFight()
{
    Pokemon *pikachu = new Pokemon("Pikachu", 100, 15, new PhysicalPlayStyle());
    Pokemon *bulbasaur = new Pokemon("Bulbasaur", 150, 10, new PhysicalPlayStyle());

    cout << CYAN << "Testing fight. Both Pokemon will attack until one faints." << RESET << endl;
    while (pikachu->getHP() > 0 && bulbasaur->getHP() > 0)
    {
        bulbasaur->takeDamage(pikachu->attack());
        pikachu->takeDamage(bulbasaur->attack());
    }

    delete pikachu;
    delete bulbasaur;
}

void runTests()
{
    // testStates();
    // testStyles();
    // testFight();
}

// void addHead()
// {
//     system("clear");
//     cout << title;
//     cout << setw(38) << left << "Your team:"
//          << "SCORE: " << SCORE << endl;
//     for (int t = 0; t < TEAMSIZE; t++)
//     {
//         cout << "\t";
//         squadMembers[t]->print();
//     }
//     cout << endl;
// }

// void playGame()
// {
//     system("clear");
//     cout << title << endl;
//     cout << "Welcome to Pokemon Fighter!" << endl;
//     int teamSize = 0;
//     do
//     {
//         cout << "Please enter the size of your Pokemon team (3 max): ";
//         cin >> teamSize;
//     } while (teamSize < 1 || teamSize > 3);
//     cout << endl;
//     Pokemon *team[teamSize];
//     Pokemon *enemies[teamSize];

//     vector<Pokemon *> *allPokemon = new vector<Pokemon *>();
//     allPokemon->push_back(new Pokemon("Pikachu", 100, 15, new PhysicalPlayStyle()));
//     allPokemon->push_back(new Pokemon("Bulbasaur", 150, 10, new PhysicalPlayStyle()));
//     allPokemon->push_back(new Pokemon("Charmander", 200, 5, new PhysicalPlayStyle()));
//     allPokemon->push_back(new Pokemon("Squirtle", 230, 4, new PhysicalPlayStyle()));
//     allPokemon->push_back(new Pokemon("Pidgey", 170, 12, new PhysicalPlayStyle()));
//     allPokemon->push_back(new Pokemon("Rattata", 100, 15, new PhysicalPlayStyle()));

//     cout << "All available Pokemon:" << endl;
//     for (int y = 0; y < allPokemon->size(); y++)
//     {
//         cout << "[" << y << "]: " << allPokemon->at(y)->getDescription() << endl;
//     }

//     for (int i = 0; i < teamSize; i++)
//     {
//         cout << "Please select your Pokemon #" << i + 1 << ": ";
//         int index = 0;
//         do
//         {
//             cin >> index;
//         } while (index < 0 || index >= allPokemon->size());
//         team[i] = allPokemon->at(index);
//         allPokemon->erase(allPokemon->begin() + index);
//     }

//     system("clear");
//     cout << title << endl;
// }

void playGame()
{
    Game *game = new Game();
    game->newGame();
    while (game->takeTurn())
    {
    };
    game->gameOver();
    delete game;
}

int main()
{
    // runTests();
    playGame();
    return 0;
}