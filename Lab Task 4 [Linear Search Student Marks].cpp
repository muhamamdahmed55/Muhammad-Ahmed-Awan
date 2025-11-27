#include <iostream>
using namespace std;


int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;     
    }
    return -1;             
}

int main() {
    const int size = 30;
    
    int roll[size];
    int pf[size], oop[size], dsa[size];

    
    cout << "Enter Roll Numbers and Marks of 30 Students:\n";
    for (int i = 0; i < size; i++) {
        cout << "\nStudent " << i + 1 << " Roll Number: ";
        cin >> roll[i];

        cout << "PF Marks: ";
        cin >> pf[i];

        cout << "OOP Marks: ";
        cin >> oop[i];

        cout << "DSA Marks: ";
        cin >> dsa[i];
    }

    int key;
    cout << "\nEnter the Roll Number to Search: ";
    cin >> key;

    
    int index = linearSearch(roll, size, key);

    if (index != -1) {
        int total = pf[index] + oop[index] + dsa[index];
        float percentage = (total / 300.0) * 100;

        cout << "\n--- Student Record Found ---\n";
        cout << "Roll Number: " << key << endl;
        cout << "PF Marks: " << pf[index] << endl;
        cout << "OOP Marks: " << oop[index] << endl;
        cout << "DSA Marks: " << dsa[index] << endl;
        cout << "Total Marks: " << total << "/300" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
    else {
        cout << "\nRecord Not Found!" << endl;
    }

    return 0;
}
