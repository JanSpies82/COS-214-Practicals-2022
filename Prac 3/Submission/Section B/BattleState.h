#ifndef BATTLESTATE_H
#define BATTLESTATE_H
#include <string>
#include <iostream>

class BattleState
{
protected:
	std::string battleStyle;

public:
	BattleState();
	virtual ~BattleState();
	virtual int handle(std::string name, int damage) = 0;
	virtual BattleState *nextState() = 0;
	std::string getBattleStyle();
};

#endif
