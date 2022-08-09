#include <iostream>
#include <string>
#include "Cannibal.h"
#include "Jaguar.h"
#include "Snake.h"
#include "Gorilla.h"

using namespace std;

void testEnemies()
{
    Enemy *cannibal = new Cannibal("Manny", 100, 20, "club", "shield");
    Enemy *jaguar = new Jaguar("Jaguar", 100, 20, "punch", "block");
    Enemy *snake = new Snake("snek", 100, 20, "bite", "block");
    Enemy *gorilla = new Gorilla("gorilla", 100, 20, "punch", "block");

    // cannibal->celebrate();
    // jaguar->celebrate();
    // snake->celebrate();
    // gorilla->celebrate();

    // cannibal->die();
    // jaguar->die();
    // snake->die();
    // gorilla->die();

    delete cannibal;
    delete jaguar;
    delete snake;
    delete gorilla;
}

void testSquadMembers()
{
    SquadMember *s1 = new SquadMember();
    SquadMember *s2 = new SquadMember("Manny");

    cout << "Name of s1: " << s1->getName() << endl;
    cout << "Name of s2: " << s2->getName() << endl;

    s1->setHP(100);
    s1->setDamage(20);
    s2->setHP(200);
    s2->setDamage(40);

    if (s1->getDamage() != 20 || s1->getHP() != 100)
    {
        cout << "s1's damage or HP is not set correctly" << endl;
    }
    if (s2->getDamage() != 40 || s2->getHP() != 200)
    {
        cout << "s2's damage or HP is not set correctly" << endl;
    }

    SquadMember *s3 = s1->clone();
    s1->setDamage(30);
    s1->setHP(300);

    if (s3->getDamage() != 20 || s3->getHP() != 100)
    {
        cout << "s3's damage or HP is not copied correctly" << endl;
    }

    cout<<"Name of s3: "<<s3->getName()<<endl;

    delete s1;
    delete s2;
    delete s3;
};

int main()
{
    // testEnemies();
    testSquadMembers();
    return 0;
}
