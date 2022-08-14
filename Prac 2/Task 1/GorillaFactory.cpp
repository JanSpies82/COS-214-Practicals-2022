#include "GorillaFactory.h"

GorillaFactory::GorillaFactory()
{
}

GorillaFactory::~GorillaFactory()
{
}

Enemy *GorillaFactory::createEnemy(std::string attack = "Fists", std::string defense = "Block")
{
    Enemy *enemy = new Gorilla(getName(), getUniform(4, 12), 1, attack, defense);
    enemy->setType("Gorilla");
    return enemy;
}
