#ifndef CANNIBAL_H
#define CANNIBAL_H
#include "Enemy.h"
class Cannibal : public Enemy
{
public:
    Cannibal(std::string name, int HP, int damage, std::string attackMove, std::string defendMove);
    ~Cannibal();
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
    Enemy *clone();
};
#endif // CANNIBAL_H