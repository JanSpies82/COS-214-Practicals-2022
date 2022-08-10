#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include "Enemy.h"
#include <cmath>
#include <random>

class EnemyFactory {
public:
    EnemyFactory();
    virtual ~EnemyFactory();
    virtual Enemy* createEnemy(std::string attack, std::string defense) = 0;
protected:
    int getNormal(int mu, int sigma);
    int getUniform(int min, int max);
    std::string getName();
    const static std::string names[];
};
#endif