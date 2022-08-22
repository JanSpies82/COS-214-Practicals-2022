#include <iostream>

#include "Aero.h"
#include "DairyMilk.h"
#include "DairyMilkBubbly.h"
#include "Lindor.h"
#include "Milkybar.h"

using namespace std;

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

void testConcreteProducts()
{
    cout << CYAN << "Testing Concrete Products" << RESET << endl;
    Confectionary *a = new Aero(5);
    Confectionary *dm = new DairyMilk(true);
    Confectionary *dmb = new DairyMilkBubbly(3);
    Confectionary *l = new Lindor(false);
    Confectionary *mb = new Milkybar(true);

    cout << "Aero: " << a->getDescription() << endl;
    cout << "Dairy Milk: " << dm->getDescription() << endl;
    cout << "Dairy Milk Bubbly: " << dmb->getDescription() << endl;
    cout << "Lindor: " << l->getDescription() << endl;
    cout << "Milkybar: " << mb->getDescription() << endl;

    delete a;
    delete dm;
    delete dmb;
    delete l;
    delete mb;
}

void runTests(){
    testConcreteProducts();
}

int main()
{
    runTests();
    return 0;
}
