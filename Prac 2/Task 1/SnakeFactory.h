#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H
#include "EnemyFactory.h"
#include "Snake.h"
class SnakeFactory : public EnemyFactory {
public:
    SnakeFactory();
    ~SnakeFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};
#endif