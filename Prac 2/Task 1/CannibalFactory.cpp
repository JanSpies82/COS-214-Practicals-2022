#include "CannibalFactory.h"
using namespace std;

CannibalFactory::CannibalFactory(){};

CannibalFactory::~CannibalFactory(){};

Enemy *CannibalFactory::createEnemy(std::string attack="Fists", std::string defense="Block")
{
    Enemy *enemy = new Cannibal(getName(), getUniform(8, 30), 6, attack, defense);
    return enemy;
}
