#include "StrongBattleState.h"
#include "NormalBattleState.h"
#include "AgileBattleState.h"
using namespace std;

StrongBattleState::StrongBattleState()
{
	battleStyle = "strong";
}

StrongBattleState::~StrongBattleState()
{
}

int StrongBattleState::handle(string name, int damage)
{
	int newdmg = damage * 2;
	cout << name << " has selected a strong battle state, and will inflict ";
	cout << newdmg << " points on the next battle attack but misses the following attack turn." << endl;
	return newdmg;
}

BattleState *StrongBattleState::nextState()
{
	int randNum = 0;
	randNum = rand() % 2;
	if (randNum == 0)
	{
		return new AgileBattleState();
	}
	else
	{
		return new NormalBattleState();
	}
	delete this;
}