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

    squadMembers = new SquadMember *[2];

    currentEnemy = NULL;
    score = 0;
    active = true;
}

Game::~Game()
{
    for (int i = 0; i < 4; i++)
    {
        delete enemyFactories[i];
    }
    delete[] enemyFactories;
    for (int i = 0; i < 2; i++)
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
    squadMembers[0]->setHP(5);
    squadMembers[0]->setDamage(5);

    squadMembers[1] = squadMembers[0]->clone();

    cout << setw(38) << left << "Your squad consists of:" << endl;
    for (int t = 0; t < 2; t++)
    {
        cout << "\t";
        squadMembers[t]->print();
    }
    cout << endl;
    cout << "You are about to embark on a dangerous journey. Are you ready?" << endl;
    cout << "(Press Enter to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Game::takeTurn()
{
    addHead();
    cout << "You delve deeper into the island.\n";
    cout << "There are two paths, left and right. Which one do you choose?\n";
    cout << "[1] Left \n[2] Right \n[9] Quit \nEnter choice: ";
    int choice = 0;
    cin >> choice;

    if (choice == 9)
    {
        gameOver("Player has quit the game.");
        return;
    }

    srand(time(0));
    Enemy *e = enemyFactories[rand() % 4]->getEnemy();
    currentEnemy = e;
    int fullHP = e->getHP();
    cout << "You find a " << e->getType() << " named " << e->getName() << endl;
    cout << "Their stats are: " << e->getHP() << " HP and " << e->getDamage() << " damage!" << endl;
    bool valid = false;
    string in;

    while (e->getHP() > 0 && alive())
    {
        do
        {
            cout << "Choose which squadmember should face this foe!\n";
            for (int y = 0; y < 2; y++)
            {
                if (!squadMembers[y]->isDead())
                    cout << "[" << y << "] " << squadMembers[y]->getName() << endl;
            }

            cout << "Your choice: ";
            in = "";
            cin >> in;
            valid = (validInp(in) && !squadMembers[stoi(in)]->isDead());
            if (!valid)
                cout << "INVALID INPUT!\nPlease try again\n\n";
        } while (!valid);

        e->attack(squadMembers[stoi(in)]);

        if (squadMembers[stoi(in)]->isDead())
        {
            cout << squadMembers[stoi(in)]->getName() << " has fallen!" << endl;
            cout << e->getName() << " still has " << e->getHP() << " HP!" << endl;
        }
        else
        {
            cout << squadMembers[stoi(in)]->getName() << " lives to fight another day and gained " << fullHP << " points!" << endl
                 << endl;
        }
    }
    if (!alive())
        return;

    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.get();

    score += fullHP;
    delete currentEnemy;
    e = NULL;
    currentEnemy = NULL;
}

bool Game::alive()
{
    return !squadMembers[0]->isDead() || !squadMembers[1]->isDead();
}

void Game::addHead()
{
    system("clear");
    cout << title;
    cout << setw(38) << left << "Your squad:"
         << "SCORE: " << score << endl;
    for (int t = 0; t < 2; t++)
    {
        cout << "\t";
        squadMembers[t]->print();
    }
    cout << endl;
}

void Game::gameOver(string message)
{
    // system("clear");
    // cout << title;
    cout << "  ___                                             \n";
    cout << " / __| __ _  _ __   ___        ___ __ __ ___  _ _ \n";
    cout << "| (_ |/ _` || \'  \\ / -_)      / _ \\\\ V // -_)| \'_|\n";
    cout << " \\___|\\__/_||_|_|_|\\___|      \\___/ \\_/ \\___||_|  \n";
    cout << message << endl;
    cout << "FINAL SCORE : " << score << endl;
    active = false;
}

bool Game::validInp(string in)
{
    return in.find_first_not_of("0123456789") == string::npos;
}