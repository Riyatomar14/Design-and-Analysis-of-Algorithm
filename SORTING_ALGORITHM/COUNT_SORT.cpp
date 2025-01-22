"
Counting Sort is a non-comparison-based sorting algorithm.
The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
  "

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
"
Worst-case: O(n).
Average-case: O(n).
Best-case: O(n).
  "
