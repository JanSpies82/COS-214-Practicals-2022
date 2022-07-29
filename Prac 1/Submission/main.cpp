#include <iostream>
#include <sstream>
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
    double *max = new double;
    if (a == NULL)
        return NULL;
    for (int t = 0; t < size; t++)
    {
        if (a[t] != NULL)
            *max = a[t];
    }
    if (*max == NULL)
        return NULL;
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

    // cout<<"input: "<<input<<" original: "<<original<<" asc: "<<asc<<endl;

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

//Task 5.2
long Ack(long m, long n){
    if (m == 0)
        return n + 1;
    if (m > 0 && n == 0){
        return Ack(m-1, 1);
    }
    if (m > 0 && n > 0)
        return Ack(m - 1, Ack(m, n - 1));

    // while (m != 0) {
    //     n = n == 0 ? 1 : Ack(m, n - 1);
    //     m--;
    // }
    // return n + 1;

    
}

int main()
{
    // Test for Task 4.2
    // int *arr = new int[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     arr[i] = i;
    // }
    // cout << "Number of even numbers: " << countEven(arr, 10) << endl;

    // Test for Task 4.3
    // double *arr = new double[10];
    // double *arr2 = new double[10];
    // double *arr3 = NULL;
    // for (int t = 0; t < 10; t++)
    // {
    //     arr[t] = t;
    // }
    // cout << "Max: " << *maximum(arr, 10) << endl;
    // cout << maximum(arr2, 10) << endl;
    // cout << maximum(arr3, 10) << endl;

    // Test for Task 5.1
    // cout << recursFunc(20, 20, false) << endl;
    // cout << recursFunc(14, 14, false) << endl;

    // Test for Task 5.2
    // cout << "The value of A(4, 2) = " << endl;
    // cout << Ack(4,2) << endl;

    return 0;
}