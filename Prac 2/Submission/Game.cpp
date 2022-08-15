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

    backup = new Backup();

    currentEnemy = NULL;
    score = 0;
    active = true;
}

Game::~Game()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Del factory " << i << endl;
        delete enemyFactories[i];
    }
    cout << "Del factories" << endl;
    delete[] enemyFactories;
    for (int i = 0; i < 2; i++)
    {
        cout << "Del squad " << i << endl;
        delete squadMembers[i];
    }
    cout << "Del squad" << endl;
    delete[] squadMembers;

    cout << "Del moves" << endl;
    delete moveHistory;
    cout << "Del current enemy" << endl;
    delete currentEnemy;
    cout << "Del backup" << endl;
    delete backup;
    cout << "end" << endl;
}

void Game::newGame()
{
    system("clear");
    active = true;
    cout << title << endl;
    cout << "Welcome to the Island!" << endl;
    cout << "Would you like to start a new game or restore a previous game? (n/r): ";
    string in;
    cin >> in;
    while (in != "n" && in != "r")
    {
        cout << "Invalid input. Please enter n or r: ";
        cin >> in;
    }
    if (in == "r")
    {
        CheckPoint *c = backup->getCheckPoint();
        if (c == NULL)
            cout << "No previous game to restore. Starting new game." << endl;
        else
        {
            cout << "Restoring checkpoint with score " << c->getScore() << ". " << endl;
            for (int i = 0; i < 2; i++)
            {
                delete squadMembers[i];
                squadMembers[i] = new SquadMember(c->getSquadMembers()[i]->getName());
                squadMembers[i]->setHP(c->getSquadMembers()[i]->getHP());
                squadMembers[i]->setDamage(c->getSquadMembers()[i]->getDamage());
            }
            score = c->getScore();

            delete c;
            cout << "(Press Enter to continue)" << endl;
            cin.ignore();
            cin.get();
            return;
        }
    }
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    squadMembers[0] = new SquadMember(name);
    squadMembers[0]->setHP(15);
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
    cout << "[1] Left \n[2] Right \n[3] Load Previous Checkpoint\n[9] Quit \nEnter choice: ";
    int choice = 0;
    cin >> choice;

    if (choice == 9)
    {
        active = false;
        cout << "\nPlayer has quit the game.\n";
        return;
    }
    else if (choice == 3)
    {
        CheckPoint *chk = backup->getCheckPoint();
        if (chk == NULL)
        {
            cout << "No previous saved checkpoints" << endl;
            CheckPoint *c = new CheckPoint(squadMembers, score);
            backup->addCheckpoint(c);
        }
        else
        {
            cout << "Restoring checkpoint with score " << chk->getScore() << ". " << endl;
            for (int i = 0; i < 2; i++)
            {
                delete squadMembers[i];
                squadMembers[i] = new SquadMember(chk->getSquadMembers()[i]->getName());
                squadMembers[i]->setHP(chk->getSquadMembers()[i]->getHP());
                squadMembers[i]->setDamage(chk->getSquadMembers()[i]->getDamage());
            }
            score = chk->getScore();

            delete chk;
            cout << "(Press Enter to continue)" << endl;
            cin.ignore();
            cin.get();
        }
    }
    else if (choice != 1 && choice != 2)
    {
        cout << "Invalid input. Please enter 1, 2, 3 or 9.\n";
        cout << "(Press Enter to continue)" << endl;
        cin.ignore();
        cin.get();
        return;
    }

    srand(time(0));
    moveHistory = new MoveHistory();
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
            cout << "[3] Undo previous move\n";
            cout << "[4] Quit and save\n";

            cout << "Your choice: ";
            in = "";
            cin >> in;
            if (!(validInp(in)))
                cout << "INVALID INPUT!\nPlease try again\n\n";
            else if (in == "3")
            {
                Move *m = moveHistory->getMove();
                if (m != NULL)
                {
                    for (int q = 0; q < 2; q++)
                    {
                        squadMembers[q]->setHP(m->getSquadMembers()[q]->getHP());
                        squadMembers[q]->setDamage(m->getSquadMembers()[q]->getDamage());
                    }
                    currentEnemy->setDamage(m->getEnemy()->getDamage());
                    currentEnemy->setHP(m->getEnemy()->getHP());

                    score = m->getScore();

                    cout << "You undid your last move.\n";
                    delete m;
                    valid = false;
                }
                else
                {
                    cout << "No moves to undo!\n";
                    valid = false;
                }
            }
            else if (in == "4")
            {
                cout << "You have quit the game.\n";
                CheckPoint *c = new CheckPoint(squadMembers, score);
                backup->addCheckpoint(c);
                active = false;
                valid = true;
                return;
            }
            else if (!squadMembers[stoi(in)]->isDead())
            {
                Move *m = new Move(squadMembers, currentEnemy, score);
                moveHistory->addMove(m);
                valid = true;
            }
            else
                cout << "INVALID INPUT!\nPlease try again\n\n";

        } while (!valid);
        cout << endl;
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
    {
        cout << "\nAll squad members have been killed!\n";
        return;
    }

    score += fullHP;

    CheckPoint *c = new CheckPoint(squadMembers, score);
    backup->addCheckpoint(c);
    cout << "Checkpoint saved.\n";
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.get();

    delete currentEnemy;
    delete moveHistory;
    e = NULL;
    currentEnemy = NULL;
}

bool Game::alive()
{
    return (!squadMembers[0]->isDead() || !squadMembers[1]->isDead()) && active;
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

void Game::gameOver()
{
    cout << "  ___                                             \n";
    cout << " / __| __ _  _ __   ___        ___ __ __ ___  _ _ \n";
    cout << "| (_ |/ _` || \'  \\ / -_)      / _ \\\\ V // -_)| \'_|\n";
    cout << " \\___|\\__/_||_|_|_|\\___|      \\___/ \\_/ \\___||_|  \n";
    cout << "FINAL SCORE : " << score << endl;
    active = false;
}

bool Game::validInp(string in)
{
    return in.find_first_not_of("0123456789") == string::npos;
}