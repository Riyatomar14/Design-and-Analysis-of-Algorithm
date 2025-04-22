#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i, int &comparisons) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2;// right = 2*i + 2

    // If left child is larger than root
    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    // If right child is larger than largest so far
    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, comparisons);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n, int &comparisons) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisons);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0, comparisons);
    }
}

int main() {
    int arr[] = {7, 3, 9, 12, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    heapSort(arr, n, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
