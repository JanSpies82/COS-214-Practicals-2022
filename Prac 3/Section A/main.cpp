#include <iostream>
#include <vector>

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
    cout << "Empty Lindt function: " << lb->getDescription() << endl;

    delete cf;
    delete nf;
    delete lf;

    delete dm;
    delete dmb;
    delete m;
    delete a;
    delete l;
    delete lb;
}

void runTests()
{
    testConcreteProducts();
    testFactories();
}

void confectionaryDemo()
{
    ConfectionaryFactory **factories = new ConfectionaryFactory *[3];
    factories[0] = new CadburyFactory();
    factories[1] = new NestleFactory();
    factories[2] = new LindtFactory();

    vector<Confectionary *> *confections = new vector<Confectionary *>();
    cout << "Enter the number of the factory you want to use to create Aerated chocolate: ";
    cout << "\n[0] Cadbury\n[1] Nestle\n[2] Lindt\n";
    cout << "Choice: ";
    int f;
    cin >> f;

    cout << "Enter the amount of aerated chocolates you want to create: ";
    int amount;
    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        cout << "Enter the amount of bubbles per cubic cm for chocolate #" << i + 1 << ": ";
        int bubbles;
        cin >> bubbles;
        confections->push_back(factories[f]->createAeratedChocolate(bubbles));
    }

    cout << endl
         << "Enter the number of the factory you want to use to create Chocolate: ";
    cout << "\n[0] Cadbury\n[1] Nestle\n[2] Lindt\n";
    cout << "Choice: ";
    cin >> f;

    cout << "Enter the amount of chocolates you want to create: ";
    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        cout << "Enter whether chocolate #" << i + 1 << " is a slab: ";
        bool slab;
        cin >> slab;
        confections->push_back(factories[f]->createChocolate(slab));
    }

    cout << "Now let us create an empty Lindt confection" << endl;
    confections->push_back(factories[2]->createAeratedChocolate(0));

    cout << "Here is the descriptions of all confections you created: " << endl;
    for (int i = 0; i < confections->size(); i++)
    {
        cout << confections->at(i)->getDescription() << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete factories[i];
    }
    delete[] factories;
    for (int t = 0; t < confections->size(); t++)
    {
        delete confections->at(t);
    }
    delete confections;
}

int main()
{
    // runTests();
    confectionaryDemo();

    return 0;
}
