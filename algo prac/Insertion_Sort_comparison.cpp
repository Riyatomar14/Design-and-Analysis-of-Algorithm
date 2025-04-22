#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare elements to insert key at the correct position
        while (j >= 0 && arr[j] > key) {
            comparisons++; // One comparison in while condition
            arr[j + 1] = arr[j];
            j--;
        }

        // If while loop ends due to arr[j] <= key
        if (j >= 0)
            comparisons++; // Count the last failed comparison

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {7, 3, 9, 12, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    insertionSort(arr, n, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}




