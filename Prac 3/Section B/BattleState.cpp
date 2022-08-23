#include "BattleState.h"
using namespace std;

BattleState::BattleState()
{
}

BattleState::~BattleState()
{
}

int BattleState::handle(string name, int damage)
{
	return 0;
}

string BattleState::getBattleStyle()
{
	return this->battleStyle;
}
