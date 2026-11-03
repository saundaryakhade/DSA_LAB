#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string title;
    string artist;
    string duration;
    Node* next;
};

Node* head = NULL;
Node* last = NULL;
Node* current = NULL;

void printSong(Node* p)
{
    cout << "Song ID : " << p->id << endl;
    cout << "Title : " << p->title << endl;
    cout << "Artist : " << p->artist << endl;
    cout << "Duration : " << p->duration << endl;
}

void addSong()
{
    Node* newNode = new Node;

    cout << "Enter song ID: ";
    cin >> newNode->id;
    cin.ignore();

    cout << "Enter song title: ";
    getline(cin, newNode->title);

    cout << "Enter artist name: ";
    getline(cin, newNode->artist);

    cout << "Enter duration (mm:ss): ";
    getline(cin, newNode->duration);

    if (head == NULL)
    {
        head = newNode;
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = head;
        last->next = newNode;
        last = newNode;
    }

    cout << "Song added.\n";
}

void displayPlaylist()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    do
    {
        cout << endl;
        printSong(temp);
        temp = temp->next;
    } while (temp != head);
}

void playNext()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    if (current == NULL)
        current = head;
    else
        current = current->next;

    cout << "Now playing:\n";
    printSong(current);
}

void searchSong()
{
    int id;

    cout << "Enter song ID to search: ";
    cin >> id;

    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->id == id)
        {
            cout << "Song found.\n";
            printSong(temp);
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Song not found.\n";
}

void deleteSong()
{
    int id;

    cout << "Enter song ID to delete: ";
    cin >> id;

    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;
    Node* prev = last;

    bool found = false;

    do
    {
        if (temp->id == id)
        {
            found = true;
            break;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    if (!found)
    {
        cout << "Song not found.\n";
        return;
    }

    if (temp == head && temp == last)
    {
        head = NULL;
        last = NULL;
        current = NULL;
    }
    else
    {
        prev->next = temp->next;

        if (temp == head)
            head = temp->next;

        if (temp == last)
            last = prev;

        if (current == temp)
            current = temp->next;
    }

    delete temp;

    cout << "Song deleted.\n";
}

void freeList()
{
    if (head == NULL)
        return;

    last->next = NULL;

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    last = NULL;
    current = NULL;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGEMENT =====\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Next Song\n";
        cout << "4. Search Song\n";
        cout << "5. Delete Song\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                playNext();
                break;

            case 4:
                searchSong();
                break;

            case 5:
                deleteSong();
                break;

            case 6:
                freeList();
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
