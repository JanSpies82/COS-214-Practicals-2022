#include "Antivirus.h"
#include "Root.h"
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
    cout << "Antivirus: The subject " << subject->getName() << " has been updated." << endl;
}