#include "Enemy.h"

Enemy::Enemy(std::string name, int HP, int damage, std::string attackMove, std::string defendMove){
    this->name = name;
    this->HP = HP;
    this->damage = damage;
    this->attackMove = attackMove;
    this->defendMove = defendMove;
}
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