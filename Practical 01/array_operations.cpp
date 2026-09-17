#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, pos, item, key;

    // Read number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Traversal
    cout << "\nArray elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Insertion
    cout << "\n\nEnter position for insertion: ";
    cin >> pos;

    cout << "Enter element to insert: ";
    cin >> item;

    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = item;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Deletion
    cout << "\n\nEnter position for deletion: ";
    cin >> pos;

    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Search
    cout << "\n\nEnter element to search: ";
    cin >> key;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "Element not found";
    }

    return 0;
}