#include "JaguarFactory.h"
using namespace std;

JaguarFactory::JaguarFactory(){};

JaguarFactory::~JaguarFactory(){};

Enemy *JaguarFactory::createEnemy(std::string attack="Claws", std::string defense="Block")
{
    Enemy *enemy = new Jaguar(getName(), getNormal(10, 3), 4, attack, defense);
    return enemy;
}
