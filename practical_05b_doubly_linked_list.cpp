#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int pnr;
    string name;
    int age;
    int trainNo;
    int seatNo;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void printTicket(Node* p)
{
    cout << "PNR : " << p->pnr << endl;
    cout << "Passenger : " << p->name << endl;
    cout << "Age : " << p->age << endl;
    cout << "Train Number : " << p->trainNo << endl;
    cout << "Seat Number : " << p->seatNo << endl;
}

void addReservation()
{
    Node* newNode = new Node;

    cout << "Enter PNR number: ";
    cin >> newNode->pnr;

    cin.ignore();

    cout << "Enter passenger name: ";
    getline(cin, newNode->name);

    cout << "Enter age: ";
    cin >> newNode->age;

    cout << "Enter train number: ";
    cin >> newNode->trainNo;

    cout << "Enter seat number: ";
    cin >> newNode->seatNo;

    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;

    cout << "Reservation added.\n";
}

void displayForward()
{
    if (head == NULL)
    {
        cout << "No reservations.\n";
        return;
    }

    cout << "\nReservations (first to last)\n";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << endl;
        printTicket(temp);
        temp = temp->next;
    }
}

void displayBackward()
{
    if (tail == NULL)
    {
        cout << "No reservations.\n";
        return;
    }

    cout << "\nReservations (last to first)\n";

    Node* temp = tail;

    while (temp != NULL)
    {
        cout << endl;
        printTicket(temp);
        temp = temp->prev;
    }
}

void searchReservation()
{
    int pnr;

    cout << "Enter PNR number to search: ";
    cin >> pnr;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->pnr == pnr)
        {
            cout << "\nReservation found.\n";
            printTicket(temp);
            return;
        }

        temp = temp->next;
    }

    cout << "Reservation not found.\n";
}

void cancelReservation()
{
    int pnr;

    cout << "Enter PNR number to cancel: ";
    cin >> pnr;

    Node* temp = head;

    while (temp != NULL && temp->pnr != pnr)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Reservation not found.\n";
        return;
    }

    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    if (temp->next == NULL)
        tail = temp->prev;
    else
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Reservation cancelled.\n";
}

void freeList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== TRAIN RESERVATION SYSTEM =====\n";
        cout << "1. Add Reservation\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Search Reservation\n";
        cout << "5. Cancel Reservation\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addReservation();
        else if (choice == 2)
            displayForward();
        else if (choice == 3)
            displayBackward();
        else if (choice == 4)
            searchReservation();
        else if (choice == 5)
            cancelReservation();
        else if (choice == 6)
        {
            freeList();
            cout << "Program ended.\n";
        }
        else
            cout << "Invalid choice.\n";

    } while (choice != 6);

    return 0;
}
