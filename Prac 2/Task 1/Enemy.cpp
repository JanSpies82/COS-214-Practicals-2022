#include "Enemy.h"

Enemy::Enemy(std::string name, int HP, int damage, std::string attackMove, std::string defendMove)
{
    this->name = name;
    this->HP = HP;
    this->damage = damage;
    this->attackMove = attackMove;
    this->defendMove = defendMove;
}

Enemy::~Enemy()
{
}

void Enemy::attack(SquadMember *z)
{
    if (z == NULL)
        return;

    while (z->getHP() > 0 && z->isDead() == false)
    {
        if (hitSquadMember(z))
        {
            celebrate();
        }
        else if (getHit(z))
        {
            die();
            return;
        }
    }
}

int Enemy::takeDamage(int dmg)
{
    this->HP -= (dmg >= 0 ? dmg : 0);
    return this->HP;
}

std::string Enemy::getName()
{
    return name;
};
int Enemy::getHP()
{
    return HP;
};
int Enemy::getDamage()
{
    return damage;
};
std::string Enemy::getAttackMove()
{
    return attackMove;
};
std::string Enemy::getDefendMove()
{
    return defendMove;
};

std::string Enemy::getType()
{
    return type;
};

void Enemy::setType(std::string t)
{
    type = t;
};

void Enemy::setDamage(int damage)
{
    this->damage = damage;
};

void Enemy::setHP(int HP)
{
    this->HP = HP;
};

void Enemy::setAttackMove(std::string attackMove)
{
    this->attackMove = attackMove;
};

void Enemy::setDefendMove(std::string defendMove)
{
    this->defendMove = defendMove;
};