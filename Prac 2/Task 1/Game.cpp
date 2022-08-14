#include "Game.h"
using namespace std;

const string Game::title = "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n█░▄▄▀█░▄▀█▀███▀█░▄▄█░▄▄▀█▄░▄█░██░█░▄▄▀█░▄▄███▄░▄█░▄▄█░██░▄▄▀█░▄▄▀█░▄▀█\n█░▀▀░█░█░██░▀░██░▄▄█░██░██░██░██░█░▀▀▄█░▄▄████░██▄▄▀█░██░▀▀░█░██░█░█░█\n█░██░█▄▄████▄███▄▄▄█▄██▄██▄███▄▄▄█▄█▄▄█▄▄▄███▀░▀█▄▄▄█▄▄█▄██▄█▄██▄█▄▄██\n▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";

Game::Game()
{
    enemyFactories = new EnemyFactory *[4];
    enemyFactories[0] = new CannibalFactory();
    enemyFactories[1] = new JaguarFactory();
    enemyFactories[2] = new SnakeFactory();
    enemyFactories[3] = new GorillaFactory();

    squadMembers = new SquadMember *[3];
}

Game::~Game()
{
    for (int i = 0; i < 4; i++)
    {
        delete enemyFactories[i];
    }
    delete[] enemyFactories;
    for (int i = 0; i < 3; i++)
    {
        delete squadMembers[i];
    }
    delete[] squadMembers;
}

void Game::newGame()
{
    system("clear");
    cout << title << endl;
    cout << "Welcome to the Jungle!" << endl;
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    squadMembers[0] = new SquadMember(name);
    squadMembers[0]->setHP(25);
    squadMembers[0]->setDamage(5);

    squadMembers[1] = squadMembers[0]->clone();
    squadMembers[2] = squadMembers[0]->clone();

    cout << "Your squad consists of: " << endl;
    for (int t = 0; t < 3; t++)
    {
        squadMembers[t]->print();
    }
    cout << endl;
}

void Game::run()
{
}
