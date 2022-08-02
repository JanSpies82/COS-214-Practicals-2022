#ifndef JAGUARFACTORY_H
#define JAGUARFACTORY_H
#include "EnemyFactory.h"
class JaguarFactory : public EnemyFactory {
public:
    JaguarFactory();
    Enemy* createEnemy(std::string attack, std::string defense)
}
#endif