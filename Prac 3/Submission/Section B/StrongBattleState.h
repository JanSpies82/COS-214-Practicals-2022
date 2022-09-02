#ifndef STRONGBATTLESTATE_H
#define STRONGBATTLESTATE_H
#include "BattleState.h"
class StrongBattleState : public BattleState
{

public:
	StrongBattleState();
	~StrongBattleState();
	int handle(std::string name, int damage);
	BattleState *nextState();
};

#endif
