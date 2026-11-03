#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

struct Request
{
    int id;
    string customer;
    string issue;
};

class CircularQueue
{
    Request requests[SIZE];
    int front, rear, count;

public:

    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == SIZE;
    }

    void addRequest(int id, string customer, string issue)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot accept request.\n";
            return;
        }

        rear = (rear + 1) % SIZE;

        requests[rear].id = id;
        requests[rear].customer = customer;
        requests[rear].issue = issue;

        count++;

        cout << "Request #" << id
             << " added for " << customer << ".\n";
    }

    void resolveRequest()
    {
        if (isEmpty())
        {
            cout << "No pending requests to resolve.\n";
            return;
        }

        Request r = requests[front];

        front = (front + 1) % SIZE;
        count--;

        cout << "Resolved request #" << r.id
             << " (" << r.customer
             << " - " << r.issue << ").\n";
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "No pending requests.\n";
            return;
        }

        Request r = requests[front];

        cout << "Next to serve -> "
             << r.id << " | "
             << r.customer << " | "
             << r.issue << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Pending requests ("
             << count << "/" << SIZE << "):\n";

        for (int i = 0; i < count; i++)
        {
            int idx = (front + i) % SIZE;

            cout << "[Slot " << idx << "] #"
                 << requests[idx].id << " | "
                 << requests[idx].customer << " | "
                 << requests[idx].issue << endl;
        }
    }
};

int main()
{
    CircularQueue q;

    int choice, id;
    string customer, issue;

    do
    {
        cout << "\n--- SERVICE REQUEST SYSTEM ---\n";
        cout << "1. Add request\n";
        cout << "2. Resolve request\n";
        cout << "3. Show next request\n";
        cout << "4. Display all\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Request ID: ";
                cin >> id;

                cout << "Customer name: ";
                cin >> customer;

                cout << "Issue: ";
                cin >> issue;

                q.addRequest(id, customer, issue);
                break;

            case 2:
                q.resolveRequest();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
