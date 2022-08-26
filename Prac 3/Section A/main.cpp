#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

#include "Aero.h"
#include "DairyMilk.h"
#include "DairyMilkBubbly.h"
#include "Lindor.h"
#include "Milkybar.h"

#include "CadburyFactory.h"
#include "NestleFactory.h"
#include "LindtFactory.h"

#include "Basket.h"

#include "MothersDay.h"
#include "ValentinesDay.h"
#include "SpringDay.h"

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

void calculateBasket(Basket *b)
{
    cout << "--------------------------------------------------------------------" << endl;
    double total = 0;
    for (int d = 0; d < b->getSize(); d++)
    {
        cout << "Confectionary #" << d + 1 << ": " << b->getConfectionary(d)->getDescription() << endl;
        total += b->getConfectionary(d)->getPrice();
    }
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Total for basket: R" << setprecision(5) << total << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void basketDemo()
{
    ConfectionaryFactory **factories = new ConfectionaryFactory *[3];
    factories[0] = new CadburyFactory();
    factories[1] = new NestleFactory();
    factories[2] = new LindtFactory();

    Basket *basket = new Basket();
    cout << "The list of available chocolates is: " << endl;
    cout << "[0] DairyMilk\n[1] DairyMilk Bubbly\n[2] Milkybar\n";
    cout << "[3] Aero\n[4] Lindor\n";
    cout << "Enter how many different types of chocolate you would like to add to your basket: ";
    int f;
    do
    {
        cout << "Choice: ";
        cin >> f;
        if (!cin.good())
        {
            f = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (f <= 0 || f > 5);

    for (int h = 0; h < f; h++)
    {
        system("clear");
        cout << "The list of available chocolates is: " << endl;
        cout << "[0] DairyMilk\n[1] DairyMilk Bubbly\n[2] Milkybar\n";
        cout << "[3] Aero\n[4] Lindor\n";
        cout << "Choose chocolate #" << h + 1 << " to add to your basket : ";
        int chocInd = -1;
        do
        {
            cin >> chocInd;
            if (!cin.good())
            {
                chocInd = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (chocInd < 0 || chocInd > 4);

        cout << "Enter the amount of chocolates you want to add to your basket: ";
        int amount;
        do
        {
            cout << "Amount: ";
            cin >> amount;
            if (!cin.good())
            {
                amount = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (amount < 0);

        for (int i = 0; i < amount; i++)
        {
            if (chocInd % 2 == 0)
                cout << "Enter whether chocolate #" << i + 1 << " is a slab: ";
            else
                cout << "Enter the amount of bubbles per cubic cm for chocolate #" << i + 1 << ": ";
            int bubbles;
            bool slab;
            do
            {
                cin >> bubbles;
                if (!cin.good())
                {
                    bubbles = -1;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (bubbles == -1);
            slab = bubbles;

            if (chocInd < 2)
                basket->add((chocInd % 2 == 0) ? factories[0]->createChocolate(slab) : factories[0]->createAeratedChocolate(bubbles));
            else if (chocInd < 4)
                basket->add((chocInd % 2 == 0) ? factories[1]->createChocolate(slab) : factories[1]->createAeratedChocolate(bubbles));
            else if (chocInd == 4)
                basket->add(factories[2]->createChocolate(slab));
            else
                basket->add(factories[2]->createAeratedChocolate(1));
        }
        cout << "Please press Enter to continue. . . ";
        cin.ignore();
        cin.get();
    }

    system("clear");
    cout << "Here is the descriptions of all confections you created: " << endl;
    calculateBasket(basket);

    for (int i = 0; i < 3; i++)
    {
        delete factories[i];
    }
    delete[] factories;
    delete basket;
}

void testDiscounts()
{
    ConfectionaryFactory **factories = new ConfectionaryFactory *[3];
    factories[0] = new CadburyFactory();
    factories[1] = new NestleFactory();
    factories[2] = new LindtFactory();

    Basket *basket = new Basket();

    for (int q = 0; q < 3; q++)
    {
        for (int h = 0; h < 2; h++)
        {
            for (int w = 0; w < 3; w++)
            {
                if (h == 0)
                    basket->add(factories[q]->createChocolate(w));
                else
                    basket->add(factories[q]->createAeratedChocolate(h));
            }
        }
    }

    cout << YELLOW << "Without discount: " << RESET << endl;
    cout << "R" << setprecision(5) << basket->getPrice() << endl;

    if (!basket->canAddDiscount())
        cout << RED << "canAddDiscount Failed" << RESET << endl;
    else
        cout << GREEN << "canAddDiscount Success" << RESET << endl;

    Component *m = new MothersDay(basket);

    cout << YELLOW << "Mothers day discount: " << RESET << endl;
    cout << "R" << setprecision(5) << basket->getPrice() << endl;

    if (m->canAddDiscount())
        cout << RED << "canAddDiscount Failed" << RESET << endl;
    else
        cout << GREEN << "canAddDiscount Success" << RESET << endl;

    Component *s = new SpringDay(m);

    cout << YELLOW << "Spring day discount (should stay the same): " << RESET << endl;
    cout << "R" << setprecision(5) << basket->getPrice() << endl;

    for (int i = 0; i < 3; i++)
    {
        delete factories[i];
    }
    delete[] factories;
    delete s;
}

int main()
{
    // runTests();
    // confectionaryDemo();
    // basketDemo();
    testDiscounts();

    // TODO abstract out getPrice function to component?
    //  Discount object is added last to chain
    //  When discount object is created it sets all childrens discount value to its value
    //  Each component has a discount attribute that is set to 0 by default
    //  Each component has a function to check whether it is eligible for discount
    //  Each object returns its price with the discount included based on whether it is eligible for discount in getPrice

    // Each object has a function to say whether a new discount object has been added to the chain

    return 0;
}
