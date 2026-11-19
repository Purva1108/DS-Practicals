
#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string name;
    bool favourite;
    Song *next;
};

class Playlist
{
    Song *head, *current;
    bool repeat;

public:
    Playlist()
    {
        head = NULL;
        current = NULL;
        repeat = false;
    }

    void addSong()
    {
        Song *newSong = new Song;

        cout << "Enter song name: ";
        getline(cin >> ws, newSong->name);

        newSong->favourite = false;

        if (head == NULL)
        {
            head = newSong;
            newSong->next = head;
            current = head;
        }
        else
        {
            Song *temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newSong;
            newSong->next = head;
        }

        cout << "Song added successfully!\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song *temp = head;

        cout << "\n--- Playlist ---\n";

        do
        {
            cout << temp->name;

            if (temp->favourite)
                cout << " [Favourite]";

            if (temp == current)
                cout << " <-- Current Song";

            cout << endl;
            temp = temp->next;

        } while (temp != head);
    }

    void playCurrent()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "Playing: " << current->name << endl;

        if (repeat)
            cout << "Repeat is ON.\n";
    }

    void nextSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (repeat)
        {
            cout << "Repeat is ON. Playing the same song: "
                 << current->name << endl;
            return;
        }

        current = current->next;

        cout << "Playing next song: "
             << current->name << endl;
    }

    void previousSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (repeat)
        {
            cout << "Repeat is ON. Playing the same song: "
                 << current->name << endl;
            return;
        }

        Song *temp = head;

        // Find the song before the current song
        while (temp->next != current)
        {
            temp = temp->next;
        }

        current = temp;

        cout << "Playing previous song: "
             << current->name << endl;
    }

    void searchSong()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        string name;
        cout << "Enter song name to search: ";
        getline(cin >> ws, name);

        Song *temp = head;

        do
        {
            if (temp->name == name)
            {
                cout << "Song found: " << temp->name << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Song not found.\n";
    }

    void deleteSong()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        string name;
        cout << "Enter song name to delete: ";
        getline(cin >> ws, name);

        Song *temp = head;
        Song *prev = NULL;

        do
        {
            if (temp->name == name)
            {
                if (temp->next == temp)
                {
                    head = NULL;
                    current = NULL;
                }
                else
                {
                    if (temp == head)
                    {
                        Song *last = head;

                        while (last->next != head)
                            last = last->next;

                        head = head->next;
                        last->next = head;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    if (current == temp)
                        current = temp->next;
                }

                delete temp;
                cout << "Song deleted successfully!\n";
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        cout << "Song not found.\n";
    }

    void toggleFavourite()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        string name;
        cout << "Enter song name: ";
        getline(cin >> ws, name);

        Song *temp = head;

        do
        {
            if (temp->name == name)
            {
                temp->favourite = !temp->favourite;

                if (temp->favourite)
                    cout << "Added to favourites!\n";
                else
                    cout << "Removed from favourites!\n";

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Song not found.\n";
    }

    void displayFavourites()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song *temp = head;
        bool found = false;

        cout << "\n--- Favourite Songs ---\n";

        do
        {
            if (temp->favourite)
            {
                cout << temp->name << endl;
                found = true;
            }

            temp = temp->next;

        } while (temp != head);

        if (!found)
            cout << "No favourite songs.\n";
    }

    void toggleRepeat()
    {
        repeat = !repeat;

        if (repeat)
            cout << "Repeat is ON.\n";
        else
            cout << "Repeat is OFF.\n";
    }

    ~Playlist()
    {
        if (head == NULL)
            return;

        Song *temp = head->next;

        while (temp != head)
        {
            Song *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        delete head;
    }
};

int main()
{
    Playlist p;
    int choice;

    do
    {
        cout << "\n--- MUSIC PLAYLIST MANAGER ---\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Current Song\n";
        cout << "4. Next Song\n";
        cout << "5. Previous Song\n";
        cout << "6. Search Song\n";
        cout << "7. Delete Song\n";
        cout << "8. Add/Remove Favourite\n";
        cout << "9. Display Favourite Songs\n";
        cout << "10. Repeat Song ON/OFF\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p.addSong();
            break;

        case 2:
            p.display();
            break;

        case 3:
            p.playCurrent();
            break;

        case 4:
            p.nextSong();
            break;

        case 5:
            p.previousSong();
            break;

        case 6:
            p.searchSong();
            break;

        case 7:
            p.deleteSong();
            break;

        case 8:
            p.toggleFavourite();
            break;

        case 9:
            p.displayFavourites();
            break;

        case 10:
            p.toggleRepeat();
            break;

        case 11:
            cout << "Exiting playlist.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 11);

    return 0;
}
