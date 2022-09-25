#include "Driver.h"
using namespace std;

#include "File.h"
#include "AsynchronousDirectory.h"
#include "SynchronousDirectory.h"
const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

Driver::Driver()
{
    root = new Root();
    current = root;
    active = true;

    root->addChild(new AsynchronousDirectory("sub1"));
    root->addChild(new AsynchronousDirectory("sub2"));
    root->addChild(new File("file1"));
    root->addChild(new File("file2"));
    ((Directory *)root->getChild(0))->addChild(new AsynchronousDirectory("submore"));
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
}

void Driver::moveToDirec()
{
    bool endpoint = false;
    bool ldir = current->listDirectory();
    string name;

    while (!endpoint && ldir)
    {
        cout << "Enter the name of the sub-directory you would like to navigate to or enter \"#\" to exit." << endl;
        cout << "Name: " << YELLOW;
        cin >> name;
        cout << RESET;
        if (name == "#")
        {
            endpoint = true;
            continue;
        }

        try
        {
            current = (Directory *)current->access(name);
        }
        catch (...)
        {
            cout << "That is an invalid name" << endl;
            continue;
        }
        ldir = current->listDirectory();
    }
}

void Driver::createHeader()
{
    cout << GREEN << "WELCOME TO THE DRIVER PROGRAM" << RESET << endl;
}

int Driver::getOperation()
{
    cout << "You are currently in: " << BLUE << current->getName() << RESET << endl;
    cout << "Please choose an operation to perform:" << endl;
    cout << "[0] Add new Directory" << endl;
    cout << "[1] Add new File" << endl;
    cout << "[2] Delete Directory" << endl;
    cout << "[3] Delete File" << endl;
    cout << "[4] Move to sub-directory" << endl;
    cout << "[5] Move to root directory" << endl;
    cout << "[6] Create new snapshot of the current system" << endl;
    cout << "[7] Delete all snapshots" << endl;
    cout << "[8] Restore a previous snapshot" << endl;
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
    } while (ind == -1 || (ind > 9));
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
    case 4:
    {
        moveToDirec();
        break;
    }
    case 5:
    {
        current = root;
        break;
    }

    default:
        break;
    }
}