#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

class Deque
{
protected:
    string items[SIZE];
    int front, count;

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == SIZE;
    }

    void insertFront(string name)
    {
        if (isFull())
        {
            cout << "Deque is full!\n";
            return;
        }

        front = (front - 1 + SIZE) % SIZE;
        items[front] = name;
        count++;

        cout << name << " inserted at FRONT.\n";
    }

    void insertRear(string name)
    {
        if (isFull())
        {
            cout << "Deque is full!\n";
            return;
        }

        int rear = (front + count) % SIZE;
        items[rear] = name;
        count++;

        cout << name << " inserted at REAR.\n";
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!\n";
            return;
        }

        cout << items[front] << " removed from FRONT.\n";

        front = (front + 1) % SIZE;
        count--;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!\n";
            return;
        }

        int rear = (front + count - 1) % SIZE;

        cout << items[rear] << " removed from REAR.\n";
        count--;
    }

public:

    Deque()
    {
        front = 0;
        count = 0;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Front -> ";

        for (int i = 0; i < count; i++)
        {
            cout << items[(front + i) % SIZE];

            if (i < count - 1)
                cout << " | ";
        }

        cout << " <- Rear\n";
    }
};

// Input Restricted Deque
class InputRestrictedDeque : public Deque
{
public:
    void menu()
    {
        int ch;
        string name;

        do
        {
            cout << "\n--- INPUT RESTRICTED DEQUE ---\n";
            cout << "1. Insert at Rear\n";
            cout << "2. Delete from Front\n";
            cout << "3. Delete from Rear\n";
            cout << "4. Display\n";
            cout << "5. Back\n";
            cout << "Enter choice: ";

            cin >> ch;

            switch (ch)
            {
                case 1:
                    cout << "Customer name: ";
                    cin >> name;
                    insertRear(name);
                    break;

                case 2:
                    deleteFront();
                    break;

                case 3:
                    deleteRear();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        } while (ch != 5);
    }
};

// Output Restricted Deque
class OutputRestrictedDeque : public Deque
{
public:
    void menu()
    {
        int ch;
        string name;

        do
        {
            cout << "\n--- OUTPUT RESTRICTED DEQUE ---\n";
            cout << "1. Insert at Front\n";
            cout << "2. Insert at Rear\n";
            cout << "3. Delete from Front\n";
            cout << "4. Display\n";
            cout << "5. Back\n";
            cout << "Enter choice: ";

            cin >> ch;

            switch (ch)
            {
                case 1:
                    cout << "Customer name: ";
                    cin >> name;
                    insertFront(name);
                    break;

                case 2:
                    cout << "Customer name: ";
                    cin >> name;
                    insertRear(name);
                    break;

                case 3:
                    deleteFront();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        } while (ch != 5);
    }
};

int main()
{
    int choice;

    InputRestrictedDeque inputDeque;
    OutputRestrictedDeque outputDeque;

    do
    {
        cout << "\n===== SHOPPING MALL DEQUE =====\n";
        cout << "1. Input Restricted Deque\n";
        cout << "2. Output Restricted Deque\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                inputDeque.menu();
                break;

            case 2:
                outputDeque.menu();
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
