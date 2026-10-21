
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value)
{
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
            temp = temp->next;

        temp->next = newNode;
    }
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "First node deleted." << endl;
}

void deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node* temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    cout << "Last node deleted." << endl;
}

void deleteAfter()
{
    int key;
    cout << "Enter the node value after which to delete: ";
    cin >> key;

    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Given node not found." << endl;
    }
    else if (temp->next == NULL)
    {
        cout << "No node exists after the given node." << endl;
    }
    else
    {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << "Node after " << key << " deleted." << endl;
    }
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
    int choice, value;

    do
    {
        cout << "\n1. Insert at End";
        cout << "\n2. Delete First Node";
        cout << "\n3. Delete Last Node";
        cout << "\n4. Delete Node After a Given Node";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteLast();
                break;

            case 4:
                deleteAfter();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
