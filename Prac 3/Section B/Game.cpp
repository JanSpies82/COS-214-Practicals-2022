#include "Game.h"
#include "AttackPlayStyle.h"
#include "RunPlayStyle.h"
#include "PhysicalPlayStyle.h"

using namespace std;

const string Game::title = " ___  ___  _ __ ___  __ __  ___  _ _    ___  _  ___   _ _  ___  ___  ___ \n| . \\| . || / /| __]|  \\  \\| . || \\ |  | __]| |/  _] | | ||_ _|| __]| . \\ \n|  _/| | ||  \\ | _] |     || | ||   |  | _] | || [_/\\|   | | | | _] |   /\n|_|  `___'|_\\_\\|___]|_|_|_|`___'|_\\_|  |_|  |_|`____/|_|_| |_| |___]|_\\_\\ \n";

Game::Game()
{
    allPokemon = new std::vector<Pokemon *>();
    allPokemon->push_back(new Pokemon("Pikachu", 100, 15, new AttackPlayStyle()));
    allPokemon->push_back(new Pokemon("Bulbasaur", 150, 10, new AttackPlayStyle()));
    allPokemon->push_back(new Pokemon("Charmander", 200, 5, new AttackPlayStyle()));
    allPokemon->push_back(new Pokemon("Squirtle", 230, 4, new AttackPlayStyle()));
    allPokemon->push_back(new Pokemon("Pidgey", 170, 12, new AttackPlayStyle()));
    allPokemon->push_back(new Pokemon("Rattata", 100, 15, new AttackPlayStyle()));
    teamSize = 0;
    score = 0;
    enemyIndex = 0;
    active = true;
}

Game::~Game()
{
    for (int i = 0; i < allPokemon->size(); i++)
    {
        delete allPokemon->at(i);
    }
    delete allPokemon;

    for (int i = 0; i < teamSize; i++)
    {
        delete team[i];
        delete enemies[i];
    }
    delete[] team;
    delete[] enemies;
}

void Game::newGame()
{
    system("clear");
    cout << title << endl;
    cout << "Welcome to Pokemon Fighter!" << endl;
    do
    {
        cout << "Please enter the size of your Pokemon team (3 max): ";
        cin >> teamSize;
    } while (teamSize < 1 || teamSize > 3);
    cout << endl;
    team = new Pokemon *[teamSize];
    enemies = new Pokemon *[teamSize];
    for (int k = 0; k < teamSize; k++)
    {
        team[k] = NULL;
        enemies[k] = NULL;
    }

    cout << "All available Pokemon:" << endl;
    for (int y = 0; y < allPokemon->size(); y++)
    {
        cout << "[" << y << "]: " << allPokemon->at(y)->getDescription() << endl;
    }

    for (int i = 0; i < teamSize; i++)
    {
        cout << "Please select your Pokemon #" << i + 1 << ": ";
        int index = 0;
        do
        {
            cin >> index;
        } while (index < 0 || index >= allPokemon->size());
        team[i] = allPokemon->at(index);
        allPokemon->erase(allPokemon->begin() + index);
    }

    for (int r = 0; r < teamSize; r++)
    {
        int index = rand() % allPokemon->size();
        enemies[r] = allPokemon->at(index);
        allPokemon->erase(allPokemon->begin() + index);
    }

    cout << "You are ready to begin the battle!" << endl;
    cout << "Press Enter to begin..." << endl;
    cin.ignore();
    cin.get();
}

void Game::addHead()
{
    system("clear");
    cout << title << endl;
    cout << setw(45) << left << "Your team:"
         << "SCORE: " << score << endl;
    for (int t = 0; t < teamSize; t++)
    {
        cout << "\t";
        team[t]->getStatus();
    }
    cout << endl;
}

bool Game::takeTurn()
{
    if (!(active && isAlive()))
        return false;
    addHead();
    cout << "Your enemy is: ";
    enemies[enemyIndex]->getStatus();
    int fullHP = enemies[enemyIndex]->getHP();

    cout << "Choose you fighter!" << endl;
    for (int i = 0; i < teamSize; i++)
    {
        cout << "[" << i << "]: " << team[i]->getDescription() << endl;
    }
    int index = 0;
    do
    {
        cout << "Choice: ";
        cin >> index;
    } while ((index < 0 || index >= teamSize) && team[index]->getHP() > 0);

    cout << "Choose the playstyle of " << team[index]->getName() << "!" << endl;
    cout << "[0]: Attack" << endl;
    cout << "[1]: Physical" << endl;
    cout << "[2]: Run" << endl;
    cout << "Choice: ";
    int playstyle = 0;
    do
    {
        cout << "Choice: ";
        cin >> playstyle;
    } while (playstyle < 0 || playstyle > 2);

    switch (playstyle)
    {
    case 0:
        team[index]->setStyle(new AttackPlayStyle());
        break;
    case 1:
        team[index]->setStyle(new PhysicalPlayStyle());
        break;
    case 2:
        team[index]->setStyle(new RunPlayStyle());
        break;
    default:
        team[index]->setStyle(new AttackPlayStyle());
    }

    while (team[index]->getHP() > 0 && enemies[enemyIndex]->getHP() > 0)
    {
        enemies[enemyIndex]->takeDamage(team[index]->attack());
        team[index]->takeDamage(enemies[enemyIndex]->attack());
    }

    if (enemies[enemyIndex]->getHP() <= 0)
    {
        cout << team[index]->getName() << " has defeated " << enemies[enemyIndex]->getName() << "!" << endl;
        score += fullHP;
        enemyIndex++;
        if (enemyIndex >= teamSize)
        {
            cout << "You have defeated all of your enemies!" << endl;
            active = false;
        }
    }
    else
    {
        cout << team[index]->getName() << " has been defeated!" << endl;
        active = isAlive();
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
    return true;
}

bool Game::isAlive()
{
    bool a = false;
    for (int h = 0; h < teamSize; h++)
    {
        if (team[h]->getHP() > 0)
        {
            a = true;
        }
    }
    return a;
}

void Game::gameOver()
{
    system("clear");
    cout << title << endl;
    cout << endl;
    cout << "  ___                                             \n";
    cout << " / __| __ _  _ __   ___        ___ __ __ ___  _ _ \n";
    cout << "| (_ |/ _` || \'  \\ / -_)      / _ \\\\ V // -_)| \'_|\n";
    cout << " \\___|\\__/_||_|_|_|\\___|      \\___/ \\_/ \\___||_|  \n";
    cout << setw(45) << left << "Your team:"
         << "FINAL SCORE: " << score << endl;
    for (int t = 0; t < teamSize; t++)
    {
        cout << "\t";
        team[t]->getStatus();
    }
}