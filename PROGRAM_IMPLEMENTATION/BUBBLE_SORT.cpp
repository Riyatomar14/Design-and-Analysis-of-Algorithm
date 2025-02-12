#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for(int i = 0; i< n-1; i++){ // Outer loop for passes
        for(int j = 0; j < n-1-i ; j++){ // Inner loop for comparisons
            if(arr[j] > arr[j+1]){ // Compare adjacent elements
                // Swap elements
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n); // Call the bubble sort function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
