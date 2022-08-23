#include "Pokemon.h"
#include "NormalBattleState.h"
using namespace std;

Pokemon::Pokemon(string name, int HP, int damage, PlayStyle *style) : name(name), HP(HP), damage(damage), style(style)
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
	return this->damage;
}

void Pokemon::selectBattleState()
{
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
