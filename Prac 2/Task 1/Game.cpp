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
    score = 0;
    active = true;
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

    cout << setw(38) << left << "Your squad consists of:" << endl;
    for (int t = 0; t < 3; t++)
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
    cout << "You delve deeper into the jungle.\n";
    cout << "There are two paths, left and right. Which one do you choose?\n";
    cout << "[1] Left \n[2] Right \n[9] Quit \nEnter choice: ";
    int choice = 0;
    cin >> choice;

    if (choice == 9)
    {
        gameOver();
        return;
    }

    cout << "You have chosen " << choice << endl;
}

bool Game::alive()
{
    return active;
}

void Game::addHead()
{
    system("clear");
    cout << title;
    cout << setw(38) << left << "Your squad:"
         << "SCORE: " << score << endl;
    for (int t = 0; t < 3; t++)
    {
        cout << "\t";
        squadMembers[t]->print();
    }
    cout << endl;
}

void Game::gameOver()
{
    system("clear");
    cout << title;
    cout << "  ___                                             \n";
    cout << " / __| __ _  _ __   ___        ___ __ __ ___  _ _ \n";
    cout << "| (_ |/ _` || \'  \\ / -_)      / _ \\\\ V // -_)| \'_|\n";
    cout << " \\___|\\__/_||_|_|_|\\___|      \\___/ \\_/ \\___||_|  \n";
    cout << "FINAL SCORE : " << score << endl;
    active = false;
}