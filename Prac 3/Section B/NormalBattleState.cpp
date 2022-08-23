#include "NormalBattleState.h"
#include "AgileBattleState.h"
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
	BattleState *s = new AgileBattleState();
	return s;
	delete this;
}