#ifndef STRONGBATTLESTATE_H
#define STRONGBATTLESTATE_H
#include "BattleState.h"
class StrongBattleState : public BattleState
{

public:
	StrongBattleState();
	int handle(std::string name, int damage);
};

#endif
