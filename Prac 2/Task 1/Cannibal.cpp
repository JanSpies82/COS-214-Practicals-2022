#include "Cannibal.h"
using namespace std; 

Cannibal::Cannibal(string name, int HP, int damage, string attackMove, string defendMove){
    Enemy(name, HP, damage, attackMove, defendMove);
};

bool hitSquadMember(SquadMember *z){
    cout<<"Cannibal rushes towards " << z->getName() << " with a " << attackMove <<".\n";
    return (z->takeDamage(damage) <= 0);
};
void celebrate(){
    cout<<"Screams with his last breath \"I am your father\".\n";
};
bool getHit(SquadMember *z){
    cout<<"The other villagers come runing deploying " << defendMove<<".\n";
    return (takeDamage(z->getDamage()) <= 0);
};
void die(){
    cout<<"Shakes his " << attackMove << " at the player\'s remains.\n";
};