#include "SnakeFactory.h"
SnakeFactory::SnakeFactory()
{
}

SnakeFactory::~SnakeFactory()
{
}

Enemy *SnakeFactory::createEnemy(std::string attack, std::string defense)
{
    Enemy *enemy = new Snake(getName(), getNormal(6, 1), 2, attack, defense);
    return enemy;
}
