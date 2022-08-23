#include "Pokemon.h"
#include "NormalBattleState.h"
using namespace std;

Pokemon::Pokemon(string name, int HP, int damage, PlayStyle *style) : name(name), HP(HP), basedamage(damage), style(style)
{
	state = new NormalBattleState();
}

Pokemon::~Pokemon()
{
	delete state;
	delete style;
}

string Pokemon::getName()
{
	return this->name;
}

int Pokemon::getHP()
{
	return this->HP;
}

int Pokemon::getDamage()
{
	return this->turndamage;
}

void Pokemon::selectBattleState()
{
	turndamage = state->handle(name, basedamage);
	BattleState *s = state->nextState();
	delete state;
	state = s;
}

int Pokemon::attack()
{
	return 0;
}

void Pokemon::setStyle(PlayStyle *style)
{
}

void Pokemon::takeDamage(int damage)
{
}
