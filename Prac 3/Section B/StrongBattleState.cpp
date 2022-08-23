#include "StrongBattleState.h"
#include "NormalBattleState.h"
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
	BattleState *s = new NormalBattleState();
	return s;
	delete this;
}