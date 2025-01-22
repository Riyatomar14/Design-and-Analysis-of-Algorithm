#include <iostream>
using namespace std;

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    // Find the minimum and maximum element in the array
    int minElement = arr[0];
    int maxElement = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) minElement = arr[i];
        if (arr[i] > maxElement) maxElement = arr[i];
    }

    int range = maxElement - minElement + 1;

    // Create the count array and initialize it to 0
    int count[range];
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - minElement]++;
    }

    // Write sorted values back to the original array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minElement;
            count[i]--;
        }
    }
}

// Main function to test the implementation
int main() {
    int n;

    // Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Counting Sort
    countingSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
