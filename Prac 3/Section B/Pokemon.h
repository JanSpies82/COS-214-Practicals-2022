#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>
#include "PlayStyle.h"
#include "BattleState.h"

class BattleState;
class Pokemon
{
private:
	std::string name;
	int HP;
	int damage;
	BattleState *state;
	std::string style;

public:
	Pokemon(std::string name, int HP, int damage, PlayStyle *style);
	std::string getName();
	int getHP();
	int getDamage();
	void selectBattleState();
	int attack();
	void setStyle(PlayStyle *style);
	void takeDamage(int damage);
};

#endif
