#ifndef BATTLESTATE_H
#define BATTLESTATE_H
#include <string>
#include <iostream>

class BattleState
{
protected:
	std::string battleStyle;

public:
	virtual int handle(std::string name, int damage) = 0;
	std::string getBattleStyle();
};

#endif
