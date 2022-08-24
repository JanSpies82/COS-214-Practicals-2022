#include "Aero.h"
using namespace std;

Aero::Aero(int bubblespccm) : AeratedChocolate("Nestle", 16.11, bubblespccm)
{
    cout << "New Aero created with " << bubblespccm << " bubbles per cm" << endl;
}

Aero::~Aero()
{
    cout << "Aero destroyed" << endl;
}
