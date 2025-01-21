#include <iostream>
using namespace std;

// Function to partition the array
int partition(int a[], int low, int high) {
    int pivot = a[high]; // Pivot element
    int i = low - 1;     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (a[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(a[i], a[j]);
        }
    }
    // Place the pivot in its correct position
    swap(a[i + 1], a[high]);
    return i + 1; // Return the partition index
}

// Quick Sort function
void quickSort(int a[], int low, int high) {
    if (low < high) {
        // Partition the array around pivot and get the index of pivot
        int pi = partition(a, low, high);

        // Recursively sort elements before and after the partition
        quickSort(a, low, pi - 1);  // Sort the left subarray
        quickSort(a, pi + 1, high); // Sort the right subarray
    }
}

// Main function to test the Quick Sort
int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
