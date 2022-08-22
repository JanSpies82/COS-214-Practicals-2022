#include "DairyMilkBubbly.h"
using namespace std;

DairyMilkBubbly::DairyMilkBubbly(int bubblespccm) : AeratedChocolate("Cadbury", 18, bubblespccm)
{
    cout << "New DairyMilkBubbly created with " << bubblespccm << " bubbles per cm" << endl;
}

DairyMilkBubbly::~DairyMilkBubbly()
{
    cout << "DairyMilkBubbly destroyed" << endl;
}
