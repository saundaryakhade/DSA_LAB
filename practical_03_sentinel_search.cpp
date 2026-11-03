#include <iostream>
#include <string>
using namespace std;

void merge(string name[], string phone[], int low, int mid, int high)
{
    string tempName[50], tempPhone[50];

    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (name[i] < name[j])
        {
            tempName[k] = name[i];
            tempPhone[k] = phone[i];
            i++;
        }
        else
        {
            tempName[k] = name[j];
            tempPhone[k] = phone[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        tempName[k] = name[i];
        tempPhone[k] = phone[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        tempName[k] = name[j];
        tempPhone[k] = phone[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        name[i] = tempName[k];
        phone[i] = tempPhone[k];
    }
}

void mergeSort(string name[], string phone[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(name, phone, low, mid);
        mergeSort(name, phone, mid + 1, high);

        merge(name, phone, low, mid, high);
    }
}

int sentinelSearch(string name[], int n, string key)
{
    string last = name[n - 1];

    name[n - 1] = key;

    int i = 0;

    while (name[i] != key)
        i++;

    name[n - 1] = last;

    if (i < n - 1 || last == key)
        return i;

    return -1;
}

int main()
{
    string name[50], phone[50];
    int n;

    cout << "Enter number of friends: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin >> name[i];

        cout << "Enter mobile number: ";
        cin >> phone[i];
    }

    mergeSort(name, phone, 0, n - 1);

    cout << "\nSorted Phone Book:\n";

    for (int i = 0; i < n; i++)
        cout << name[i] << " : " << phone[i] << endl;

    string key;

    cout << "\nEnter name to search: ";
    cin >> key;

    int pos = sentinelSearch(name, n, key);

    if (pos != -1)
    {
        cout << "Friend found!\n";
        cout << "Mobile Number: " << phone[pos] << endl;
    }
    else
    {
        cout << "Friend not found.\n";

        string newPhone;

        cout << "Enter mobile number: ";
        cin >> newPhone;

        int p = 0;

        while (p < n && name[p] < key)
            p++;

        for (int i = n; i > p; i--)
        {
            name[i] = name[i - 1];
            phone[i] = phone[i - 1];
        }

        name[p] = key;
        phone[p] = newPhone;

        n++;

        cout << "\nFriend inserted successfully!\n";

        cout << "\nUpdated Phone Book:\n";

        for (int i = 0; i < n; i++)
            cout << name[i] << " : " << phone[i] << endl;
    }

    return 0;
}
