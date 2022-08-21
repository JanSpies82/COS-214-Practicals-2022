#include <iostream>
#include <string>
#include "Game.h"
// #include "SquadMember.h"

// #include "Cannibal.h"
// #include "Jaguar.h"
// #include "Snake.h"
// #include "Gorilla.h"

// #include "CannibalFactory.h"
// #include "JaguarFactory.h"
// #include "SnakeFactory.h"
// #include "GorillaFactory.h"

using namespace std;

const std::string red = "\x1B[31m";
const std::string green = "\x1B[32m";
const std::string yellow = "\x1B[33m";
const std::string blue = "\x1B[34m";
const std::string cyan = "\x1B[36m";
const std::string reset = "\x1B[0m";

void testEnemies()
{
    cout << cyan << "Testing enemies..." << reset << endl;
    Enemy *cannibal = new Cannibal("Manny", 100, 20, "club", "shield");
    Enemy *jaguar = new Jaguar("Jaguar", 100, 20, "punch", "block");
    Enemy *snake = new Snake("snek", 100, 20, "bite", "block");
    Enemy *gorilla = new Gorilla("gorilla", 100, 20, "punch", "block");

    cannibal->celebrate();
    jaguar->celebrate();
    snake->celebrate();
    gorilla->celebrate();

    cannibal->die();
    jaguar->die();
    snake->die();
    gorilla->die();

    delete cannibal;
    delete jaguar;
    delete snake;
    delete gorilla;
    cout << endl;
}

void testSquadMembers()
{
    cout << cyan << "Testing squad members..." << reset << endl;
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

    cout << "Name of s3: " << s3->getName() << endl;

    delete s1;
    delete s2;
    delete s3;

    cout << endl;
};

void testFactories()
{
    cout << cyan << "Testing factories..." << reset << endl;
    EnemyFactory *cf = new CannibalFactory();
    EnemyFactory *jf = new JaguarFactory();
    EnemyFactory *gf = new GorillaFactory();
    EnemyFactory *sf = new SnakeFactory();

    Enemy *c = cf->createEnemy("Fists", "Shield");
    Enemy *j = jf->createEnemy("Claws", "Dodge");
    Enemy *g = gf->createEnemy("Stick", "Duck");
    Enemy *s = sf->createEnemy("Bite", "Scurry");

    cout << yellow << "Cannibal:" << reset << endl;
    cout << "Name: " << c->getName() << endl;
    cout << "HP: " << c->getHP() << endl;
    cout << "Damage: " << c->getDamage() << endl;
    cout << "Attack: " << c->getAttackMove() << endl;
    cout << "Defense: " << c->getDefendMove() << endl;

    cout << yellow << "Jaguar:" << reset << endl;
    cout << "Name: " << j->getName() << endl;
    cout << "HP: " << j->getHP() << endl;
    cout << "Damage: " << j->getDamage() << endl;
    cout << "Attack: " << j->getAttackMove() << endl;
    cout << "Defense: " << j->getDefendMove() << endl;

    cout << yellow << "Gorilla:" << reset << endl;
    cout << "Name: " << g->getName() << endl;
    cout << "HP: " << g->getHP() << endl;
    cout << "Damage: " << g->getDamage() << endl;
    cout << "Attack: " << g->getAttackMove() << endl;
    cout << "Defense: " << g->getDefendMove() << endl;

    cout << yellow << "Snake:" << reset << endl;
    cout << "Name: " << s->getName() << endl;
    cout << "HP: " << s->getHP() << endl;
    cout << "Damage: " << s->getDamage() << endl;
    cout << "Attack: " << s->getAttackMove() << endl;
    cout << "Defense: " << s->getDefendMove() << endl;

    delete cf;
    delete jf;
    delete gf;
    delete sf;

    delete c;
    delete j;
    delete g;
    delete s;
    cout << endl;
}

void testAttack()
{
    cout << cyan << "Testing attack..." << reset << endl;
    Enemy *c = new Cannibal("Cannibal", 10, 2, "club", "shield");
    Enemy *j = new Jaguar("Jaguar", 10, 2, "punch", "block");
    Enemy *g = new Gorilla("Gorilla", 10, 2, "punch", "block");
    Enemy *s = new Snake("Snake", 10, 2, "bite", "block");

    SquadMember *s1 = new SquadMember("Manny");
    s1->setDamage(5);
    s1->setHP(50);

    c->attack(s1);
    j->attack(s1);
    g->attack(s1);
    s->attack(s1);

    cout << "Squad Member HP: " << s1->getHP() << endl;
    // cout<<"Enemy HP: "<<c->getHP()<<endl;

    delete c;
    delete j;
    delete g;
    delete s;

    delete s1;
    cout << endl;
}

void runTests()
{
    testEnemies();
    testSquadMembers();
    testFactories();
    testAttack();
}

int main()
{
    // Game *game = new Game();

    // bool wantsToPlay = true;

    // while (wantsToPlay)
    // {
    //     game->newGame();
    //     while (game->alive())
    //     {
    //         game->takeTurn();
    //     }
    //     game->gameOver();
    //     string input;
    //     cout << "Play again? (y/n): ";

    //     cin >> input;
    //     if (input == "n")
    //         wantsToPlay = false;
    // }

    // delete game;

    runTests();
    return 0;
}
