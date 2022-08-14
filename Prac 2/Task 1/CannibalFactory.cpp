#include "CannibalFactory.h"
using namespace std;

CannibalFactory::CannibalFactory(){};

CannibalFactory::~CannibalFactory(){};

Enemy *CannibalFactory::createEnemy(std::string attack, std::string defense)
{
    Enemy *enemy = new Cannibal(getName(), getUniform(8, 30), 6, attack, defense);
    return enemy;
}
