#ifndef GORILLA_H
#define GORILLA_H
#include "Enemy.h"
class Gorilla : public Enemy
{
public:
    Gorilla(std::string name, int HP, int damage, std::string attackMove, std::string defendMove);
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
};
#endif // GORILLA_H