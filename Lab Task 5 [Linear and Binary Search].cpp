#include <iostream>
#include <algorithm>
using namespace std;

int linearSearch(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int A[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int rollNo[100];
    cout << "Enter " << n << " roll numbers: ";
    for (int i = 0; i < n; i++)
        cin >> rollNo[i];

    int choice, key;
    cout << "\n1. Linear Search (unsorted)\n2. Binary Search (sorted)\nEnter your choice: ";
    cin >> choice;

    cout << "Enter roll number to search: ";
    cin >> key;

    int result = -1;
    if (choice == 1) {
        result = linearSearch(rollNo, n, key);
    } else if (choice == 2) {
        sort(rollNo, rollNo + n); // sort before binary search
        result = binarySearch(rollNo, n, key);
    } else {
        cout << "Invalid choice!";
        return 0;
    }

    if (result != -1)
        cout << "Roll number found at index: " << result << endl;
    else
        cout << "Roll number not found." << endl;

    return 0; }