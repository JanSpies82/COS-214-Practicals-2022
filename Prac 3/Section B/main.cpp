#include <string>
#include <iostream>
#include "Pokemon.h"

#include "NormalBattleState.h"
#include "AgileBattleState.h"
#include "StrongBattleState.h"

#include "AttackPlayStyle.h"
#include "RunPlayStyle.h"
#include "PhysicalPlayStyle.h"

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
    testFight();
}

int main()
{
    runTests();
    return 0;
}