#include "Jaguar.h"
using namespace std;

bool Jaguar::hitSquadMember(Enemy *z){
    cout<<"Jaguar leaps toward the " << z->getName() << " and deliver\'s a forceful " << attackMove << ".\n"; 
    return (z->takeDamage(damage) <= 0);
};
void Jaguar::celebrate(){
    cout<<"Should have fought harder soldier\n";
};
bool Jaguar::getHit(Enemy *z){
    cout<<"Growls in pain as he is maimed. Jaguar turns around and delivers " << defendMove << " against " << z->getName() <<".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void Jaguar::die(){
    cout<<"Gives one last growl before falling over.\n";
};