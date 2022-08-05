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

int main()
{
    testEnemies();
    return 0;
}
