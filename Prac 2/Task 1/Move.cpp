#include "Move.h"
using namespace std;

Move::Move(int choice)
{
    this->choice = choice;
};
Move::~Move(){};
int Move::getMove()
{
    return choice;
};