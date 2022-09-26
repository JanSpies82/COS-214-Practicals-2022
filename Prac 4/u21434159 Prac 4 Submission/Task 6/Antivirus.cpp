#include "Antivirus.h"
#include "Root.h"
#include "DirectoryState.h"
using namespace std;

Antivirus::Antivirus(Root *r) : Observer(r)
{
    subject = r;
}

Antivirus::~Antivirus()
{
}

void Antivirus::update()
{
    DirectoryState *newstate = (DirectoryState *)subject->getState();
    DirectoryState *oldstate = (DirectoryState *)state;

    if (oldstate->numChildren() == newstate->numChildren())
    {
        delete state;
        state = newstate;
        return;
    }

    bool newfile = oldstate->numChildren() < newstate->numChildren();
    bool found = false;

    DirectoryState *oldsubstate = (DirectoryState *)oldstate;
    DirectoryState *newsubstate = (DirectoryState *)newstate;
    while (!found)
    {
        if (oldsubstate->children->size() != newsubstate->children->size())
        {
            found = true;
            bool innerfound = false;
            int length = newfile ? oldsubstate->children->size() : oldsubstate->children->size() - 1;
            for (int h = 0; h < length; h++)
            {
                if (oldsubstate->children->at(h)->getName() != newsubstate->children->at(h)->getName())
                {
                    innerfound = true;
                    if (newfile)
                        cout << "New file/directory " << newsubstate->children->at(h)->getName() << " has been scanned." << endl;
                    else
                        cout << "File/directory " << oldsubstate->children->at(h)->getName() << " has been deleted." << endl;
                    break;
                }
            }
            if (newfile && !innerfound)
                cout << "New file/directory " << newsubstate->children->at(newsubstate->children->size() - 1)->getName() << " has been scanned." << endl;
            else if (!newfile && !innerfound)
                cout << "File/directory " << oldsubstate->children->at(oldsubstate->children->size() - 1)->getName() << " has been deleted." << endl;
        }
        else
        {
            for (int t = 0; t < oldsubstate->children->size(); t++)
            {
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
    delete state;
    state = newstate;
}