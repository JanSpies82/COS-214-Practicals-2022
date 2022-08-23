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
    Pokemon *p = new Pokemon("Pikachu", 100, 10, new PhysicalPlayStyle());
    p->selectBattleState();
    p->selectBattleState();
    p->selectBattleState();
    p->selectBattleState();

    delete p;
}

void runTests(){
    testStates();
}

int main()
{
    runTests();
    return 0;
}