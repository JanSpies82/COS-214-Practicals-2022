#ifndef JAGUAR_H
#define JAGUAR_H
#include "Enemy.h"
class Jaguar : public Enemy
{
public:
    Jaguar(std::string name, int HP, int damage, std::string attackMove, std::string defendMove);
    ~Jaguar();
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
    Enemy* clone();
};
#endif // JAGUAR_H