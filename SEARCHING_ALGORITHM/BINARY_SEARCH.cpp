/**
 * Algorithm steps:
 * 1. Compare target with middle element
 * 2. If target matches, return index
 * 3. If target greater, search right half
 * 4. If target smaller, search left half
 * 5. Repeat until found or subarray empty
 Note: time complexity : O(logn)
       space complexity : O(1)
**/
#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (arr[mid] < target)
            low = mid + 1;
        // If target is smaller, ignore right half
        else
            high = mid - 1;
    }

    // Target not present in array
    return -1;
}

int main() {
    int n, target;

    // Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements (must be sorted)
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input target value to search
    cout << "Enter the target value: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, n, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

