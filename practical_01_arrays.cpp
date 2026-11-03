#include <iostream>
using namespace std;

int main()
{
    int seats[10] = {0};
    int choice, seatNo;

    do
    {
        cout << "\n1. Display Seats\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nSeat Status:\n";
                for (int i = 0; i < 10; i++)
                {
                    cout << "Seat " << i + 1 << " : ";
                    if (seats[i] == 0)
                        cout << "Available\n";
                    else
                        cout << "Booked\n";
                }
                break;

            case 2:
                cout << "Enter seat number to book (1-10): ";
                cin >> seatNo;

                if (seatNo < 1 || seatNo > 10)
                    cout << "Invalid seat number!\n";
                else if (seats[seatNo - 1] == 1)
                    cout << "Seat is already booked!\n";
                else
                {
                    seats[seatNo - 1] = 1;
                    cout << "Ticket booked successfully!\n";
                }
                break;

            case 3:
                cout << "Enter seat number to cancel (1-10): ";
                cin >> seatNo;

                if (seatNo < 1 || seatNo > 10)
                    cout << "Invalid seat number!\n";
                else if (seats[seatNo - 1] == 0)
                    cout << "Seat is not booked!\n";
                else
                {
                    seats[seatNo - 1] = 0;
                    cout << "Booking cancelled successfully!\n";
                }
                break;

            case 4:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
