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

#include "Card.h"
#include "Note.h"
#include "Ribbon.h"
#include "Flower.h"

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
        cout << confections->at(i)->getDescription();
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
        cout << b->getConfectionary(d)->getDescription();
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

void testAddOns()
{
    Component *c = new Ribbon("Red", new Card("A bit longer message", new Note("For You!!", new Flower("Rose", new Aero(25)))));
    cout << CYAN << "Description: " << RESET << endl;
    cout << c->getDescription();

    cout << CYAN << "Price: " << RESET << endl;
    cout << "R" << setprecision(5) << c->getPrice() << endl;

    Component *m = new SpringDay(c);
    cout << CYAN << "Description with discount: " << RESET << endl;
    cout << m->getDescription();

    cout << CYAN << "Price with discount: " << RESET << endl;
    cout << "R" << setprecision(5) << m->getPrice() << endl;

    Component *s = new MothersDay(m);

    cout << CYAN << "Price should stay the same as discount: " << RESET << endl;
    cout << "R" << setprecision(5) << s->getPrice() << endl;

    delete s;
    c = NULL;
    m = NULL;
    cout << endl
         << endl;

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

    Component *hamper = new MothersDay(new Ribbon("Blue", new Card("Have a wonderfull day!", new Flower("Orchid", basket))));
    basket = NULL;
    cout << endl
         << CYAN << "Description of basket with discount with discount: " << RESET << endl;
    cout << hamper->getDescription();
    cout << CYAN << "Price of basket with discount: " << RESET << endl;
    cout << "R" << setprecision(5) << hamper->getPrice() << endl
         << endl;

    for (int i = 0; i < 3; i++)
    {
        delete factories[i];
    }
    delete[] factories;
    delete hamper;

    cout << endl
         << endl;

    Component *c1 = new Note("Third", new Note("Second", new Note("First", new Aero(25))));
    Component *c2 = new Card("Third", new Card("Second", new Card("First", new Aero(25))));
    Component *c3 = new Flower("Lily", new Note("Second", new Ribbon("Red", new Card("Second", new Flower("Rose", new Note("First", new Card("First", new Ribbon("Blue", new Lindor(1)))))))));

    cout << CYAN << "Description of Aero with three notes added: " << RESET << endl;
    cout << c1->getDescription();
    cout << CYAN << "Price of Aero with three notes added: " << RESET << endl;
    cout << "R" << setprecision(5) << c1->getPrice() << endl
         << endl;

    cout << CYAN << "Description of Aero with three cards added: " << RESET << endl;
    cout << c2->getDescription();
    cout << CYAN << "Price of Aero with three cards added: " << RESET << endl;
    cout << "R" << setprecision(5) << c2->getPrice() << endl
         << endl;

    cout << CYAN << "Description of Lindor with multiple duplicate Add Ons added: " << RESET << endl;
    cout << c3->getDescription();
    cout << CYAN << "Price of Lindor with multiple duplicate Add Ons added: " << RESET << endl;
    cout << "R" << setprecision(5) << c3->getPrice() << endl
         << endl;

    delete c1;
    delete c2;
    delete c3;
}

void createSummary(Component *c)
{
    system("clear");
    cout << CYAN << "Summary" << RESET << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << c->getDescription();
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Total Price: R" << setprecision(5) << c->getPrice() << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Press Enter to continue . . .";
    cin.ignore();
    cin.get();
}

void demoAll()
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
    createSummary(basket);

    system("clear");
    Component *c = basket;
    basket = NULL;
    cout << "Here is a list of all available add-ons: " << endl;
    cout << "[0] Ribbon\n[1] Note\n[2] Card\n[3] Flower\n";
    cout << "Enter how many different types of add-ons you would like to add to your basket: ";
    f = -1;
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
    } while (f <= 0 || f > 4);

    for (int h = 0; h < f; h++)
    {
        system("clear");
        cout << "Here is a list of all available add-ons: " << endl;
        cout << "[0] Ribbon\n[1] Note\n[2] Card\n[3] Flower\n";
        cout << "Choose add-on #" << h + 1 << " to add to your basket : ";
        int addInd = -1;
        do
        {
            cin >> addInd;
            if (!cin.good())
            {
                addInd = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (addInd < 0 || addInd > 3);
        cout << "Enter the amount of add-ons you want to add to your basket: ";
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
            if ((addInd == 1 || addInd == 2) && amount > 1)
            {
                cout << "You can only add one note or card to your basket.\n";
                amount = 1;
            }
        } while (amount < 0);

        for (int i = 0; i < amount; i++)
        {
            string color = "";
            string text = "";
            string variety = "";
            switch (addInd)
            {
            case 0:
                cout << "Enter the color of ribbon #" << i + 1 << ": ";
                cin >> color;
                c = new Ribbon(color, c);
                break;
            case 1:
                cout << "Enter the text of note #" << i + 1 << ": ";
                cin >> text;
                c = new Note(text, c);
                break;
            case 2:
                cout << "Enter the text of card #" << i + 1 << ": ";
                cin >> text;
                c = new Card(text, c);
                break;
            case 3:
                cout << "Enter the variety of flower #" << i + 1 << ": ";
                cin >> variety;
                c = new Flower(variety, c);
                break;
            }
        }
    }
    createSummary(c);

    system("clear");
    cout << "Please choose a discount option below:" << endl;
    cout << "[0] No discount\n[1] Mother's Day (14 May)\n[2] Spring Day (1 September)\n[3] Valentine's Day (14 February)\n";

    int discount = -1;
    do
    {
        cout << "Choice: ";
        cin >> discount;
        if (!cin.good())
        {
            discount = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (discount < 0 || discount > 3);

    switch (discount)
    {
    case 0:
        break;
    case 1:
        c = new MothersDay(c);
        break;
    case 2:
        c = new SpringDay(c);
        break;
    case 3:
        c = new ValentinesDay(c);
        break;
    }

    createSummary(c);

    for (int i = 0; i < 3; i++)
    {
        delete factories[i];
    }
    delete[] factories;
    delete c;
}

void runTests()
{
    testConcreteProducts();
    testFactories();
    testDiscounts();
    testAddOns();
}

int main()
{
    // runTests();
    confectionaryDemo(); //Task 2.3
    // basketDemo(); // Task 3.1
    // demoAll();

    return 0;
}
