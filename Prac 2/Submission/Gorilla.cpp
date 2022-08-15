#include "Gorilla.h"
using namespace std;

Gorilla::Gorilla(std::string name, int HP, int damage, std::string attackMove, std::string defendMove) : Enemy(name, HP, damage, attackMove, defendMove){};

Gorilla::~Gorilla(){};

bool Gorilla::hitSquadMember(SquadMember *z)
{
    if (z == NULL)
        return true;
    cout << "Gorilla slams his fists on the ground, growls and hits " << z->getName() << " with " << attackMove << ".\n";
    return (z->takeDamage(damage) <= 0);
};
void Gorilla::celebrate()
{
    cout << "Player tried in vain to save himself.\n";
};
bool Gorilla::getHit(SquadMember *z)
{
    if (z == NULL)
        return true;
    cout << z->getName() << " attacks " << name << endl;
    cout << "Roars and hits his chest in anger.\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Gorilla::die()
{
    cout << "The earth shakes as the gorilla falls to the ground.\n";
    HP = 0;
};
Enemy *Gorilla::clone()
{
    Enemy *e = new Gorilla(name, HP, damage, attackMove, defendMove);
    e->setType(type);
    return e;
}