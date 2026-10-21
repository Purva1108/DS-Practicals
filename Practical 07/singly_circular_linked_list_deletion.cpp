
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

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
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

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }

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

    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node* temp = head;

        while (temp->next->next != head)
            temp = temp->next;

        Node* last = temp->next;
        temp->next = head;
        delete last;
    }

    cout << "Last node deleted." << endl;
}

void deleteAfter()
{
    int key;
    cout << "Enter node value after which to delete: ";
    cin >> key;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == key)
            break;

        temp = temp->next;
    } while (temp != head);

    if (temp->data != key)
    {
        cout << "Node not found." << endl;
    }
    else if (temp->next == head)
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

    cout << "Circular Linked List: ";

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
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
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 2: deleteFirst(); break;
            case 3: deleteLast(); break;
            case 4: deleteAfter(); break;
            case 5: display(); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
