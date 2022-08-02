#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include "Enemy.h"
class EnemyFactory {
public:
    EnemyFactory();
    virtual ~EnemyFactory();
    virtual Enemy* createEnemy(std::string attack, std::string defense) = 0;
protected:
    std::string getName();
}
#endif