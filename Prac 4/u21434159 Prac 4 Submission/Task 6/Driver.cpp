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
    cout << "Which type of directory would you like to add?" << endl;
    cout << "[0] Synchronous" << endl;
    cout << "[1] Asynchronous" << endl;
    int choice = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice == -1 || choice < 0 || choice > 1);

    string name;
    cout << "Enter the name of the directory: " << YELLOW;
    cin >> name;
    cout << RESET;

    try
    {
        if (choice == 0)
        {
            current->addChild(new SynchronousDirectory(name));
        }
        else
        {
            current->addChild(new AsynchronousDirectory(name));
        }
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }

    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}

void Driver::addNewFile()
{
    cout << "Enter the name of the file you would like to add." << endl;
    cout << "Name: " << YELLOW;
    string name = "";
    cin >> name;
    cout << RESET;
    File *f = new File(name);
    cout << "Enter the first line of text in " << name << "." << endl;
    cout << YELLOW;
    string contents = "";
    cin >> contents;
    cout << RESET;
    f->appendContents(contents);
    current->addChild(f);
    cout << "Success. Press Enter to continue . . .";
    cin.get();
    cin.ignore();
}

void Driver::deleteDirec()
{
    if (current == root)
    {
        cout << RED << "You cannot delete the root directory!" << RESET << endl;
        cout << "Press Enter to continue. . .";
        cin.get();
        cin.ignore();
        return;
    }
    string name = current->getName();
    current = (Directory *)current->getParent();
    current->removeChild(name);
    cout << "Press Enter to continue. . .";
    cin.get();
    cin.ignore();
}

void Driver::deleteFile()
{
    bool hasFile = current->listFile();
    if (!hasFile)
    {
        cout << "Press Enter to continue. . .";
        cin.get();
        cin.ignore();
        return;
    }
    string name = "";
    cout << "Enter the name of the file you would like to delete." << endl;
    cout << "Name: " << YELLOW;
    cin >> name;
    cout << RESET;

    try
    {
        current->removeFile(name);
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    cout << "Press Enter to continue. . .";
    cin.get();
    cin.ignore();
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

void Driver::addSnapshot()
{
    try
    {
        root->createSnapshot();
        cout << "Snapshot created successfully" << endl;
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    cout << "Press Enter to continue. . .";
    cin.get();
    cin.ignore();
}

void Driver::deleteSnapshots()
{
    try
    {
        root->clearAll();
        cout << "Snapshots deleted successfully" << endl;
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    cout << "Press Enter to continue. . .";
    cin.get();
    cin.ignore();
}

void Driver::restoreSnapshot()
{
    try
    {
        root->restoreSnapshot();
        current = root;
        cout << "Snapshot restored successfully" << endl;
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    cout << "Press Enter to continue. . .";
    cin.get();
    cin.ignore();
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
    cout << "[9] View contents of current directory" << endl;
    cout << "[10] Quit" << endl;
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
    } while (ind == -1 || (ind > 10));
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
    case 10:
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
    case 1:
    {
        addNewFile();
        break;
    }
    case 2:
    {
        deleteDirec();
        break;
    }
    case 3:
    {
        deleteFile();
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
    case 6:
    {
        addSnapshot();
        break;
    }
    case 7:
    {
        deleteSnapshots();
        break;
    }
    case 8:
    {
        restoreSnapshot();
        break;
    }
    case 9:
    {
        cout << current->print();
        cout << "Press Enter to continue . . .";
        cin.get();
        cin.ignore();
        break;
    }
    default:
        break;
    }
}