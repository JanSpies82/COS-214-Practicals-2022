#include "Snake.h"
using namespace std;

Snake::Snake(string name, int HP, int damage, string attackMove, string defendMove) : Enemy(name, HP, damage, attackMove, defendMove){};

Snake::~Snake(){};

bool Snake::hitSquadMember(SquadMember *z)
{
    cout << "Snake wraps around " << z->getName() << " and uses " << attackMove << ".\n";
    return (z->takeDamage(damage) <= 0);
};
void Snake::celebrate()
{
    cout << "Player tried strongly till the end.\n";
};
bool Snake::getHit(SquadMember *z)
{
    cout << "Slithers rapidly searching for safety and employs " << defendMove << ".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Snake::die()
{
    cout << "Hisses and curls up as he is defeated.\n";
    HP = 0;
};