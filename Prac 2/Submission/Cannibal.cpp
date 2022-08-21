#include "Cannibal.h"
using namespace std;

Cannibal::Cannibal(string name, int HP, int damage, string attackMove, string defendMove) : Enemy(name, HP, damage, attackMove, defendMove){};

Cannibal::~Cannibal(){};

bool Cannibal::hitSquadMember(SquadMember *z)
{
    if (z == NULL)
        return true;
    cout << "Cannibal rushes towards " << z->getName() << " with a " << attackMove << ".\n";
    return (z->takeDamage(damage) <= 0);
};
void Cannibal::celebrate()
{
    cout << "Shakes his " << attackMove << " at the player\'s remains.\n";
};
bool Cannibal::getHit(SquadMember *z)
{
    if (z == NULL)
        return true;
    cout << z->getName() << " attacks " << name << endl;
    cout << "The other villagers come runing deploying " << defendMove << ".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Cannibal::die()
{
    cout << "Screams with his last breath \"I am your father\".\n";
    HP = 0;
};

Enemy *Cannibal::clone()
{
    Enemy *e = new Cannibal(name, HP, damage, attackMove, defendMove);
    e->setType(type);
    return e;
}