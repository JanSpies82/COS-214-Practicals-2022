#include "Cannibal.h"
using namespace std; 

bool hitSquadMember(Enemy *z){
    cout<<"Cannibal rushes towards " << z->getName() << " with a " << attackMove <<".\n";
};
void celebrate(){
    cout<<"Screams with his last breath \"I am your father\".\n";
};
bool getHit(Enemy *z){
    cout<<"The other villagers come running deploying " << defendMove<<".\n";
};
void die(){
    cout<<"Shakes his " << attackMove << " at the player\'s remains.\n";
};