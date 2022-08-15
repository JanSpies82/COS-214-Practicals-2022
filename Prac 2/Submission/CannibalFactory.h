#ifndef CANNIBALFACTORY_H
#define CANNIBALFACTORY_H
#include "EnemyFactory.h"
#include "Cannibal.h"
class CannibalFactory : public EnemyFactory {
public:
    CannibalFactory();
    ~CannibalFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};
#endif