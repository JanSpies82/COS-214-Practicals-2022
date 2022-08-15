#include "Jaguar.h"
using namespace std;

Jaguar::Jaguar(std::string name, int HP, int damage, std::string attackMove, std::string defendMove) : Enemy(name, HP, damage, attackMove, defendMove){};

Jaguar::~Jaguar(){};

bool Jaguar::hitSquadMember(SquadMember *z)
{
    if (z == NULL)
        return true;
    cout << "Jaguar leaps toward " << z->getName() << " and delivers a forceful " << attackMove << ".\n";
    return (z->takeDamage(damage) <= 0);
};
void Jaguar::celebrate()
{
    cout << "Should have fought harder soldier\n";
};
bool Jaguar::getHit(SquadMember *z)
{
    if (z == NULL)
        return true;
    cout << z->getName() << " attacks " << name << endl;
    cout << "Growls in pain as he is maimed. Jaguar turns around and delivers " << defendMove << " against " << z->getName() << ".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Jaguar::die()
{
    cout << "Gives one last growl before falling over.\n";
    HP = 0;
};
Enemy *Jaguar::clone()
{
    Enemy *e = new Jaguar(name, HP, damage, attackMove, defendMove);
    e->setType(type);
    return e;
}