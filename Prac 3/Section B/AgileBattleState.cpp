#include "AgileBattleState.h"
#include "StrongBattleState.h"
using namespace std;
AgileBattleState::AgileBattleState()
{
	battleStyle = "agile";
}

AgileBattleState::~AgileBattleState()
{
}

int AgileBattleState::handle(string name, int damage)
{
	int newdmg = damage * 0.75;
	cout << name << " has selected an agile battle state, and is allowed two battle ";
	cout << "attacks in one turn and will deal " << newdmg << " points." << endl;
	return newdmg;
}

BattleState *AgileBattleState::nextState()
{
	BattleState *s = new StrongBattleState();
	return s;
	delete this;
}