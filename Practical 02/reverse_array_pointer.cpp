#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamically allocate memory
    int *arr = (int *)malloc(n * sizeof(int));

    // Check memory allocation
    if (arr == NULL)
    {
        cout << "Memory Allocation Failed";
        return 0;
    }

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }

    // Print array in reverse order
    cout << "Array in reverse order: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << *(arr + i) << " ";
    }

    // Free allocated memory
    free(arr);

    return 0;
}