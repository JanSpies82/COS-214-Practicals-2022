#ifndef SNAKE_H
#define SNAKE_H
#include "Enemy.h"
class Snake : public Enemy
{
public:
    Snake(std::string name, int HP, int damage, std::string attackMove, std::string defendMove);
    ~Snake();
    bool hitSquadMember(SquadMember *z);
    void celebrate();
    bool getHit(SquadMember *z);
    void die();
    Enemy* clone();
};
#endif // SNAKE_H