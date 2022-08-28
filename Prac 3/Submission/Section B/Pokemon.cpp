#include "Pokemon.h"
#include "NormalBattleState.h"
using namespace std;

Pokemon::Pokemon(string name, int HP, int damage, PlayStyle *style) : name(name), HP(HP), basedamage(damage), style(style)
{
	state = new NormalBattleState();
	turndamage = damage;
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
	if (HP > 0)
	{
		selectBattleState();
		cout << name << style->attack() << endl;
		return turndamage;
	}
	else
	{
		cout << name << " has fainted and cannot attack." << endl;
		return 0;
	}
}

void Pokemon::setStyle(PlayStyle *style)
{
	delete this->style;
	this->style = style;
}

void Pokemon::takeDamage(int damage)
{
	HP -= damage;
	HP < 0 ? HP = 0 : HP = HP;
}

string Pokemon::getDescription()
{
	string out = "";
	out += name + " has " + to_string(HP) + " HP ";
	out += "and " + to_string(basedamage) + " base damage.";
	return out;
}

void Pokemon::getStatus()
{
	if (HP > 0)
		cout << name << ": " << HP << "HP with " << turndamage << " current damage" << endl;
	else
		cout << name << ": fainted" << endl;
}