#include "Gorilla.h"
using namespace std;

bool hitSquadMember(SquadMember *z){
    cout<<"Gorilla slams his fists on the ground, growls and hits " << z->getName() <<" with " <<attackMove <<".\n";
    return (z->takeDamage(damage) <= 0);
};
void celebrate(){
    cout<< "Player tried in vain to save himself.\n";
};
bool getHit(SquadMember *z){
    cout<<"Roars and hits his chest in anger.\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void die(){
    cout<<"The earth shakes as the gorilla falls to the ground.\n";
};