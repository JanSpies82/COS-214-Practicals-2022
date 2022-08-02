#ifndef GORILLAFACTORY_H
#define GORILLAFACTORY_H
#include "EnemyFactory.h"
class GorillaFactory : public EnemyFactory {
public:
    GorillaFactory();
    Enemy* createEnemy(std::string attack, std::string defense)
}
#endif