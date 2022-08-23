#ifndef AGILEBATTLESTATE_H
#define AGILEBATTLESTATE_H

#include "BattleState.h"
class AgileBattleState : public BattleState
{

public:
	AgileBattleState();
	int handle(std::string name, int damage);
};

#endif
