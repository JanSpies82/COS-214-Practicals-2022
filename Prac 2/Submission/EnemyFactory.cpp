#include "EnemyFactory.h"
using namespace std;

const string EnemyFactory::names[] = {"Mr Burns", "Skelator", "Gargamel", "Dr Doom", "Shredder", "Megatron", "Plankton"};
const string EnemyFactory::attackMoves[] = {"Punch", "Hit", "Strangle", "Bite", "Throw"};
const string EnemyFactory::defenceMoves[] = {"Hide", "Block", "Shield", "Jump", "Crouch"};

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

int EnemyFactory::getNormal(int mu, int sigma)
{
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<> d{mu, sigma};
    return round(d(gen));
}

int EnemyFactory::getUniform(int min, int max)
{
    random_device rd{};
    mt19937 gen{rd()};
    uniform_int_distribution<> d(min, max);
    return d(gen);
}

std::string EnemyFactory::getName()
{
    srand(time(0));
    return names[rand() % names->size()];
}

Enemy *EnemyFactory::getEnemy()
{
    srand(time(0));
    return createEnemy(attackMoves[rand() % attackMoves->size()], defenceMoves[rand() % defenceMoves->size()]);
}