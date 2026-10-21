
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Node inserted at beginning." << endl;
}

void insertEnd()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted at end." << endl;
}

void insertAfter()
{
    int key, value;

    cout << "Enter the node value after which to insert: ";
    cin >> key;

    Node* temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Given node not found." << endl;
        return;
    }

    cout << "Enter new value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully." << endl;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After a Given Node";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAfter();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
