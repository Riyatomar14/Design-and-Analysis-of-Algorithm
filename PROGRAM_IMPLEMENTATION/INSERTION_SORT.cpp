#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i]; // Element to be inserted
        int j = i - 1;

        // Shift sorted elements to the right to make space for `next`
        while (j >= 0 && a[j] > next) {
            a[j + 1] = a[j];
            j--;
        }

        // Insert `next` into the correct position
        a[j + 1] = next;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n); // Call the insertion sort function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
