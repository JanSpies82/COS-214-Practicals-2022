#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "User.h"
#include "UserManager.h"
using namespace std;

// Task 4.2
int countEven(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

// Task 4.3
double *maximum(double *a, int size)
{
    if (a == NULL)
        return NULL;
    double *max = new double;
    for (int t = 0; t < size; t++)
    {
        if (a[t] != NULL)
        {
            *max = a[t];
        }
    }
    if (*max == NULL)
    {
        delete max;
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
    return max;
}

// Task 5.1
string recursFunc(int input, int original, bool asc)
{
    if (original <= 0)
        return "";

    string s = "";
    stringstream ss;
    ss << input;
    ss >> s;
    ss.clear();

    if (input <= 0)
        return s + ", " + recursFunc(input + 7, original, true);

    if (!asc)
    {
        return s + ", " + recursFunc(input - 7, original, false);
    }
    else if (input != original)
    {
        return s + ", " + recursFunc(input + 7, original, true);
    }
    else
    {
        return s;
    }
}

// Task 5.2
long Ack(long m, long n)
{
    if (m == 0)
        return n + 1;
    if (m > 0 && n == 0)
    {
        return Ack(m - 1, 1);
    }
    if (m > 0 && n > 0)
        return Ack(m - 1, Ack(m, n - 1));
}

int main()
{
    // Test for Task 4.2
    int *intarr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        intarr[i] = i;
    }
    cout << "Number of even numbers: " << countEven(intarr, 10) << endl;
    delete intarr;

    // Test for Task 4.3
    double *darr = new double[10];
    double *darr2 = new double[10];
    double *darr3 = NULL;
    double *out = NULL;
    double *out2 = NULL;
    double *out3 = NULL;
    for (int t = 0; t < 10; t++)
    {
        darr[t] = t;
    }
    out = maximum(darr, 10);
    out2 = maximum(darr2, 10);
    out3 = maximum(darr3, 10);
    cout << "Max: " << *out << endl;
    cout << out2 << endl;
    cout << out3 << endl;

    delete darr;
    delete darr2;
    delete darr3;
    delete out;
    delete out2;
    delete out3;

    // Test for Task 5.1
    cout << recursFunc(20, 20, false) << endl;
    cout << recursFunc(14, 14, false) << endl;

    // Test for Task 5.2
    cout << "The value of A(4, 2) = " << endl;
    cout << Ack(4, 2) << endl;

    // Test for Task 6
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    User *user = new User("username", "mysecretpassword");
    UserManager *userManager = new UserManager(user);
    userManager->Backup();
    user->SetPassword("pa$$w0rd");
    userManager->Backup();
    user->SetPassword("5t@rw@r5");
    userManager->Backup();
    user->SetPassword("bigB@ng");
    std::cout << "\n";
    userManager->ShowHistory();
    std::cout << "\nClient: Now, let's rollback!\n\n";
    userManager->Undo();
    std::cout << "\nClient: Once more!\n\n";
    userManager->Undo();
    delete user;
    delete userManager;

    return 0;
}