#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H
#include "EnemyFactory.h"
class SnakeFactory : public EnemyFactory {
public:
    SnakeFactory();
    Enemy* createEnemy(std::string attack, std::string defense)
}
#endif