#include "Game.h"
#include "AttackPlayStyle.h"
#include "RunPlayStyle.h"
#include "PhysicalPlayStyle.h"

using namespace std;

const string Game::title = " ___  ___  _ __ ___  __ __  ___  _ _    ___  _  ___   _ _  ___  ___  ___ \n| . \\| . || / /| __]|  \\  \\| . || \\ |  | __]| |/  _] | | ||_ _|| __]| . \\ \n|  _/| | ||  \\ | _] |     || | ||   |  | _] | || [_/\\|   | | | | _] |   /\n|_|  `___'|_\\_\\|___]|_|_|_|`___'|_\\_|  |_|  |_|`____/|_|_| |_| |___]|_\\_\\ \n";
const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

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
        if (allPokemon->at(i) != NULL)
            delete allPokemon->at(i);
    }
    delete allPokemon;

    for (int i = 0; i < teamSize; i++)
    {
        if (team[i] != NULL)
            delete team[i];
    }
    for (int j = 0; j < 6 - teamSize; j++)
    {
        if (enemies[j] != NULL)
            delete enemies[j];
    }
    delete[] team;
    delete[] enemies;
}

void Game::newGame()
{
    system("clear");
    cout << CYAN << title << RESET << endl;
    cout << "Welcome to Pokemon Fighter!" << endl;
    do
    {
        cout << "Please enter the size of your Pokemon team (3 max): ";
        cin >> teamSize;
        if (!cin.good())
        {
            teamSize = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (teamSize < 1 || teamSize > 3);
    cout << endl;
    team = new Pokemon *[teamSize];
    enemies = new Pokemon *[6 - teamSize];
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
        int index = 0;
        do
        {
            cout << "Please select your Pokemon #" << i + 1 << ": ";
            cin >> index;
            if (!cin.good())
            {
                index = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (index < 0 || index > 5);
        team[i] = allPokemon->at(index);
        allPokemon->at(index) = NULL;
    }

    int count = 0;
    for (int r = 0; r < 6; r++)
    {
        if (allPokemon->at(r) != NULL)
            enemies[count++] = allPokemon->at(r);
        allPokemon->at(r) = NULL;
    }

    cout << "You are ready to begin the battle!" << endl;
    cout << "Press Enter to begin..." << endl;
    cin.ignore();
    cin.get();
}

void Game::addHead()
{
    system("clear");
    cout << CYAN << title << RESET << endl;
    cout << setw(47) << left << "Your team:"
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
        if (team[i]->getHP() > 0)
            cout << "[" << i << "]: " << team[i]->getDescription() << endl;
    }
    int index = 0;
    do
    {
        cout << "Choice: ";
        cin >> index;
        if (!cin.good())
        {
            index = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while ((index < 0 || index >= teamSize) || team[index]->getHP() == 0);

    cout << "Choose the playstyle of " << team[index]->getName() << "!" << endl;
    cout << "[0]: Attack" << endl;
    cout << "[1]: Physical" << endl;
    cout << "[2]: Run" << endl;
    int playstyle = 0;
    do
    {
        cout << "Choice: ";
        cin >> playstyle;
        if (!cin.good())
        {
            playstyle = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
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

    cout << YELLOW << "The battle begins!" << RESET << endl;
    while (team[index]->getHP() > 0 && enemies[enemyIndex]->getHP() > 0)
    {
        enemies[enemyIndex]->takeDamage(team[index]->attack());
        team[index]->takeDamage(enemies[enemyIndex]->attack());
        cout << GREEN << team[index]->getName() << " has " << team[index]->getHP() << " HP remaining!" << RESET << endl;
        cout << RED << enemies[enemyIndex]->getName() << " has " << enemies[enemyIndex]->getHP() << " HP remaining!" << RESET << endl;
        cout << endl
             << YELLOW << "The battle continues!" << RESET << endl;
    }

    if (enemies[enemyIndex]->getHP() <= 0)
    {
        cout << team[index]->getName() << " has defeated " << enemies[enemyIndex]->getName() << "!" << endl;
        score += fullHP;
        enemyIndex++;
        if (enemyIndex >= 6 - teamSize)
        {
            active = false;
        }
    }
    else
    {
        cout << team[index]->getName() << " has been defeated!" << endl;
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
            a = true;
    }
    return a;
}

void Game::gameOver()
{
    system("clear");
    cout << CYAN << title << RESET << endl;
    cout << RED;
    cout << "  ___                                             \n";
    cout << " / __| __ _  _ __   ___        ___ __ __ ___  _ _ \n";
    cout << "| (_ |/ _` || \'  \\ / -_)      / _ \\\\ V // -_)| \'_|\n";
    cout << " \\___|\\__/_||_|_|_|\\___|      \\___/ \\_/ \\___||_|  \n";
    cout << RESET;
    if (!active)
        cout << "You have defeated all of your enemies!" << endl;
    else
        cout << "You have been defeated!" << endl;
    cout << setw(45) << left << "Your team:"
         << "FINAL SCORE: " << score << endl;
    for (int t = 0; t < teamSize; t++)
    {
        cout << "\t";
        team[t]->getStatus();
    }
}