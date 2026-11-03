#include <iostream>
using namespace std;

int hashTable[10];

int hashFunction(int carNumber)
{
    return carNumber % 10;
}

void parkVehicle(int carNumber)
{
    int index = hashFunction(carNumber);
    int originalIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % 10;

        if (index == originalIndex)
        {
            cout << "Parking lot is full!\n";
            return;
        }
    }

    hashTable[index] = carNumber;
    cout << "Vehicle parked at slot " << index << endl;
}

void searchVehicle(int carNumber)
{
    int index = hashFunction(carNumber);
    int originalIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == carNumber)
        {
            cout << "Vehicle found at slot " << index << endl;
            return;
        }

        index = (index + 1) % 10;

        if (index == originalIndex)
            break;
    }

    cout << "Vehicle not found.\n";
}

void display()
{
    cout << "\nParking Lot:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << " : ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
        hashTable[i] = -1;

    int choice, carNumber;

    do
    {
        cout << "\n1. Park Vehicle\n";
        cout << "2. Search Vehicle\n";
        cout << "3. Display Parking Lot\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter vehicle number: ";
                cin >> carNumber;
                parkVehicle(carNumber);
                break;

            case 2:
                cout << "Enter vehicle number to search: ";
                cin >> carNumber;
                searchVehicle(carNumber);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
