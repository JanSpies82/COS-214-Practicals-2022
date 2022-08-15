#ifndef GORILLAFACTORY_H
#define GORILLAFACTORY_H
#include "EnemyFactory.h"
#include "Gorilla.h"
class GorillaFactory : public EnemyFactory {
public:
    GorillaFactory();
    ~GorillaFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};
#endif