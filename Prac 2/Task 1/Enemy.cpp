#include "Enemy.h"

Enemy::Enemy(std::string name, int HP, int damage, std::string attackMove, std::string defendMove){
    this->name = name;
    this->HP = HP;
    this->damage = damage;
    this->attackMove = attackMove;
    this->defendMove = defendMove;
}

Enemy::~Enemy(){
}

void Enemy::attack(SquadMember *z)
{
    while (z->getHP() > 0 && z->isDead() == false)
    {
        if (hitSquadMember(z))
        {
            celebrate();
        }
        else if (getHit(z))
        {
            die();
        }
    }
}

int Enemy::takeDamage(int dmg){
    this->HP -= dmg;
    return this->HP;
}

std::string Enemy::getName(){
    return name;
};
int Enemy::getHP(){
    return HP;
};
int Enemy::getDamage(){
    return damage;
};
std::string Enemy::getAttackMove(){
    return attackMove;
};
std::string Enemy::getDefendMove(){
    return defendMove;
};