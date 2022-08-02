#include "Enemy.h"

void Enemy::attack(Enemy *z)
{
    while (z->HP > 0 && z->die == false)
    {
        if (hitSquadMember(z))
        {
            z->die();
            celebrate();
        }
        else if (getHit(z))
        {
            die();
        }
    }
}