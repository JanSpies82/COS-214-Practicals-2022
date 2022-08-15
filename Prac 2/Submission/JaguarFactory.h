#ifndef JAGUARFACTORY_H
#define JAGUARFACTORY_H
#include "EnemyFactory.h"
#include "Jaguar.h"
class JaguarFactory : public EnemyFactory
{
public:
    JaguarFactory();
    ~JaguarFactory();
    Enemy *createEnemy(std::string attack, std::string defense);
};
#endif