#include <iostream>
using namespace std;

// Call by Value
void callByValue(int a)
{
    a = a + 10;
    cout << "Value inside Call by Value function: " << a << endl;
}

// Call by Reference using pointer
void callByReference(int *b)
{
    *b = *b + 10;
    cout << "Value inside Call by Reference function: " << *b << endl;
}

int main()
{
    int a = 20;
    int b = 20;

    // Call by Value
    cout << "Original value of a: " << a << endl;

    callByValue(a);

    cout << "Value of a after Call by Value: " << a << endl;

    // Call by Reference
    cout << "\nOriginal value of b: " << b << endl;

    callByReference(&b);

    cout << "Value of b after Call by Reference: " << b << endl;

    return 0;
}