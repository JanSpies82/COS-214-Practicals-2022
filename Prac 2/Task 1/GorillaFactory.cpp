#include "GorillaFactory.h"

GorillaFactory::GorillaFactory()
{
}

GorillaFactory::~GorillaFactory()
{
}

Enemy *GorillaFactory::createEnemy(std::string attack, std::string defense)
{
    Enemy *enemy = new Gorilla(getName(), getUniform(4, 12), 1, attack, defense);
    return enemy;
}
