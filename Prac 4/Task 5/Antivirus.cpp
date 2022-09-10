#include "Antivirus.h"
#include "Root.h"
#include "DirectoryState.h"
using namespace std;
const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";
Antivirus::Antivirus(Root *r) : Observer(r)
{
    subject = r;
}

Antivirus::~Antivirus()
{
}

void Antivirus::update()
{
    // cout << "Antivirus: The subject " << subject->getName() << " has been updated." << endl;
    // cout << RED << "BEGIN CALL" << RESET << endl;
    DirectoryState *newstate = (DirectoryState *)subject->getState();
    DirectoryState *oldstate = (DirectoryState *)state;

    if (oldstate->numChildren() == newstate->numChildren())
    {
        // cout << "Same size: " << oldstate->numChildren() << endl;
        delete state;
        state = newstate;
        return;
    }
    // cout << "1" << endl;
    // cout << BLUE << "oldstate->children->size() = " << oldstate->numChildren() << endl;
    // cout << "newstate->children->size() = " << newstate->numChildren() << RESET << endl;

    bool newfile = oldstate->numChildren() < newstate->numChildren();
    bool found = false;
    // int length = newfile ? oldstate->numChildren() : oldstate->numChildren() - 1;
    // cout << GREEN << "length = " << length << RESET << endl;
    // for (int h = 0; h < length; h++)
    // {
    //     cout << YELLOW << "h: " << h << RESET << endl;
    //     if (oldstate->children->at(h)->getName() != newstate->children->at(h)->getName())
    //     {
    //         found = true;
    //         if (newfile)
    //         {
    //             cout << "New file/directory " << newstate->children->at(h)->getName() << " has been scanned." << endl;
    //         }
    //         else
    //         {
    //             cout << "File/directory " << oldstate->children->at(h)->getName() << " has been deleted." << endl;
    //         }
    //         break;
    //     }
    // }
    // if (newfile && !found)
    // {
    //     cout << "New file/directory " << newstate->children->at(newstate->children->size() - 1)->getName() << " has been scanned." << endl;
    // }
    // else if (!newfile && !found)
    // {
    //     cout << "File/directory " << oldstate->children->at(oldstate->children->size() - 1)->getName() << " has been deleted." << endl;
    // }

    DirectoryState *oldsubstate = (DirectoryState *)oldstate;
    DirectoryState *newsubstate = (DirectoryState *)newstate;
    // cout << "2" << endl;
    while (!found)
    {
        if (oldsubstate->children->size() != newsubstate->children->size())
        {
            found = true;
            bool innerfound = false;
            // cout << BLUE << "oldsubstate->children->size() = " << oldsubstate->children->size() << endl;
            // cout << "newsubstate->children->size() = " << newsubstate->children->size() << RESET << endl;
            int length = newfile ? oldsubstate->children->size() : oldsubstate->children->size() - 1;
            // cout << GREEN << "length = " << length << RESET << endl;
            for (int h = 0; h < length; h++)
            {
                // cout << YELLOW << "h: " << h << RESET << endl;
                if (oldsubstate->children->at(h)->getName() != newsubstate->children->at(h)->getName())
                {
                    innerfound = true;
                    if (newfile)
                    {
                        cout << "New file/directory " << newsubstate->children->at(h)->getName() << " has been scanned." << endl;
                    }
                    else
                    {
                        cout << "File/directory " << oldsubstate->children->at(h)->getName() << " has been deleted." << endl;
                    }
                    break;
                }
            }
            // cout << "4" << endl;
            if (newfile && !innerfound)
            {
                cout << "New file/directory " << newsubstate->children->at(newsubstate->children->size() - 1)->getName() << " has been scanned." << endl;
            }
            else if (!newfile && !innerfound)
            {
                cout << "File/directory " << oldsubstate->children->at(oldsubstate->children->size() - 1)->getName() << " has been deleted." << endl;
            }
        }
        else
        {
            for (int t = 0; t < oldsubstate->children->size(); t++)
            {
                // cout << "3" << endl;
                if (oldsubstate->children->at(t)->numChildren() != newsubstate->children->at(t)->numChildren())
                {
                    newsubstate = (DirectoryState *)newsubstate->children->at(t);
                    oldsubstate = (DirectoryState *)oldsubstate->children->at(t);
                }
            }
        }
    }

    while (oldsubstate->getParent() != NULL)
    {
        oldsubstate = oldsubstate->getParent();
    }
    while (newsubstate->getParent() != NULL)
    {
        newsubstate = newsubstate->getParent();
    }

    // delete oldsubstate;
    // delete newsubstate;
    delete state;
    state = newstate;
    // cout << RED << "END CALL" << RESET << endl;
}