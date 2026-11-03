#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    string phone;
    int duration;
    Node* next;
};

Node* head = NULL;

void printCall(Node* p)
{
    cout << "Caller Name : " << p->name << endl;
    cout << "Phone Number : " << p->phone << endl;
    cout << "Duration : " << p->duration << " min" << endl;
}

void addCall()
{
    Node* newNode = new Node;

    cout << "Enter caller name: ";
    getline(cin, newNode->name);

    cout << "Enter phone number: ";
    getline(cin, newNode->phone);

    cout << "Enter call duration (minutes): ";
    cin >> newNode->duration;
    cin.ignore();

    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Call added.\n";
}

void displayCalls()
{
    if (head == NULL)
    {
        cout << "Call log is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << endl;
        printCall(temp);
        temp = temp->next;
    }
}

void searchCall()
{
    string number;

    cout << "Enter phone number to search: ";
    getline(cin, number);

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->phone == number)
        {
            cout << "Call found.\n";
            printCall(temp);
            return;
        }

        temp = temp->next;
    }

    cout << "Call not found.\n";
}

void deleteCall()
{
    string number;

    cout << "Enter phone number to delete: ";
    getline(cin, number);

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->phone != number)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Call not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Call deleted.\n";
}

void freeList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== CALL LOG MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Call\n";
        cout << "2. Display All Calls\n";
        cout << "3. Search Call\n";
        cout << "4. Delete Call\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
            addCall();
        else if (choice == 2)
            displayCalls();
        else if (choice == 3)
            searchCall();
        else if (choice == 4)
            deleteCall();
        else if (choice == 5)
        {
            freeList();
            cout << "Program ended.\n";
        }
        else
            cout << "Invalid choice.\n";

    } while (choice != 5);

    return 0;
}
