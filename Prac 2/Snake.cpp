#include "Snake.h"
using namespace std;

bool Snake::hitSquadMember(Enemy *z){
    cout<<"Snake wraps around " << z->getName() << " and uses " << attackMove << ".\n";
    return (z->takeDamage(damage) <= 0);
};
void Snake::celebrate(){
    cout<<"Player tried strongly till the end.\n"
};
bool Snake::getHit(Enemy *z){
    cout<<"Slithers rapidly searching for safety and employs " << defendMove <<".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Snake::die(){
    cout<<"Hisses and curls up as he is defeated.\n";
};