#include "NormalBattleState.h"
#include "AgileBattleState.h"
#include "StrongBattleState.h"
using namespace std;

NormalBattleState::NormalBattleState()
{
	battleStyle = "normal";
}

NormalBattleState::~NormalBattleState()
{
}

int NormalBattleState::handle(string name, int damage)
{
	cout << name << " has no special battle state, normal battle attack ";
	cout << "will deal " << damage << " points." << endl;
	return damage;
}

BattleState *NormalBattleState::nextState()
{
	int randNum = 0;
	randNum = rand() % 2;
	if (randNum == 0)
	{
		return new StrongBattleState();
	}
	else
	{
		return new AgileBattleState();
	}
	delete this;
}