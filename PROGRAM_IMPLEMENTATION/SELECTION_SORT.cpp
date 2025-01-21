#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        int maxIdx = 0; // Assume the first element is the max
        for (int j = 1; j <= i; j++) { // Find the max in the range [0, i]
            if (a[j] > a[maxIdx]) {
                maxIdx = j;
            }
        }
        // Swap the elements without using a header file
        int temp = a[i];
        a[i] = a[maxIdx];
        a[maxIdx] = temp;
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

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
