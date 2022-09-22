#include "Driver.h"
using namespace std;

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

Driver::Driver()
{
    root = new Root();
    active = true;
}

Driver::~Driver()
{
    delete root;
}

bool Driver::isActive()
{
    return active;
}

void Driver::addNewDirec()
{
    cout << "Where would you like to add this new directory?" << endl;
    cout << "[0] Here" << endl;
    cout << "[1] In a sub-direcory" << endl;
    int choice = -1;
    Directory *d = root;
    do
    {
        cout << "Choice: ";
        cin >> choice;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice == -1 && choice < 2);
    if (choice == 1)
    {
        bool endpoint = false;
        string name;
        while (d->listDirectory() && endpoint)
        {
            cout << "Enter the name of the sub-directory you would like to navigate to." << endl;
            cout << "Name: ";
            cin >> name;

            try
            {
                d = (Directory *)d->access(name);
            }
            catch (...)
            {
                cout << "That is an invalid name" << endl;
                continue;
            }

            // TODO create looping mechanism to navigate to sub-folder where new thing is added. Maybe helper func?
            // TODO maybe let user navigate to place first and then always add new thing there?
        }
    }
}

void Driver::createHeader()
{
    cout << GREEN << "WELCOME TO THE DRIVER PROGRAM" << RESET << endl;
}

int Driver::getOperation()
{
    cout << "Please choose an operation to perform:" << endl;
    cout << "[0] Add new Directory" << endl;
    cout << "[1] Add new File" << endl;
    cout << "[2] Create new snapshot of the current system" << endl;
    cout << "[3] Delete all snapshots" << endl;
    cout << "[4] Restore a previous snapshot" << endl;
    cout << "[9] Quit" << endl;
    int ind = -1;
    do
    {
        cout << RESET << "Option: " << YELLOW;
        cin >> ind;
        if (!cin.good())
        {
            ind = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (ind == -1 || (ind > 4 && ind != 9));
    cout << RESET;
    return ind;
}

void Driver::performAction()
{
    system("clear");
    createHeader();
    int op = getOperation();
    switch (op)
    {
    case 9:
    {
        active = false;
        return;
        break;
    }
    case 0:
    {
        addNewDirec();
        break;
    }

    default:
        break;
    }
}