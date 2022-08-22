#include <iostream>

#include "Aero.h"
#include "DairyMilk.h"
#include "DairyMilkBubbly.h"
#include "Lindor.h"
#include "Milkybar.h"

#include "CadburyFactory.h"
#include "NestleFactory.h"
#include "LindtFactory.h"

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

void testFactories()
{
    cout << CYAN << "Testing Factories" << RESET << endl;
    ConfectionaryFactory *cf = new CadburyFactory();
    ConfectionaryFactory *nf = new NestleFactory();
    ConfectionaryFactory *lf = new LindtFactory();

    Confectionary *dm = cf->createChocolate(true);
    Confectionary *dmb = cf->createAeratedChocolate(3);
    Confectionary *m = nf->createChocolate(false);
    Confectionary *a = nf->createAeratedChocolate(5);
    Confectionary *l = lf->createChocolate(false);
    Confectionary *lb = lf->createAeratedChocolate(7);

    cout << "Dairy Milk: " << dm->getDescription() << endl;
    cout << "Dairy Milk Bubbly: " << dmb->getDescription() << endl;
    cout << "Milkybar: " << m->getDescription() << endl;
    cout << "Aero: " << a->getDescription() << endl;
    cout << "Lindor: " << l->getDescription() << endl;
    cout << "Empty Lindt function: " << lb << endl;

    delete cf;
    delete nf;
    delete lf;

    delete dm;
    delete dmb;
    delete m;
    delete a;
    delete l;
    
}

void runTests()
{
    // testConcreteProducts();
    testFactories();
}

int main()
{
    runTests();
    return 0;
}
