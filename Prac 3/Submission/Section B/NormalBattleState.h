#ifndef NORMALBATTLESTATE_H
#define NORMALBATTLESTATE_H

#include "BattleState.h"
class NormalBattleState : public BattleState
{

public:
	NormalBattleState();
	~NormalBattleState();
	int handle(std::string name, int damage);
	BattleState *nextState();
};

#endif
