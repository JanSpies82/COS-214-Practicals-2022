#include "NormalBattleState.h"
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
	return 0;
}
