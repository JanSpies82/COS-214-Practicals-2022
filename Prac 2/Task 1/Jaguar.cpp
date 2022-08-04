#include "Jaguar.h"
using namespace std;

Jaguar::Jaguar(std::string name, int HP, int damage, std::string attackMove, std::string defendMove) : Enemy(name, HP, damage, attackMove, defendMove){};

bool Jaguar::hitSquadMember(SquadMember *z)
{
    cout << "Jaguar leaps toward the " << z->getName() << " and deliver\'s a forceful " << attackMove << ".\n";
    return (z->takeDamage(damage) <= 0);
};
void Jaguar::celebrate()
{
    cout << "Should have fought harder soldier\n";
};
bool Jaguar::getHit(SquadMember *z)
{
    cout << "Growls in pain as he is maimed. Jaguar turns around and delivers " << defendMove << " against " << z->getName() << ".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Jaguar::die()
{
    cout << "Gives one last growl before falling over.\n";
};