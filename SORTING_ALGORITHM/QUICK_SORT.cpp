"
Quick Sort is a divide-and-conquer algorithm
(Divide step)
1. Choose an item p(known as pivot) and partition the items of a[i...j] into two parts
 Items that are smaller than p
 Items that are greater than or equal to p
2. Recursively sort the two parts
(Conquer step)
 Do nothing!
"
" In comparison, Merge Sort spends most of the time in conquer step but very little time in divide step"
// Function to partition the array--> this function find the correct position of the pivot element and return its index to the merge function
int partition(int a[], int p, int r) {
    int pivot = a[r]; // Pivot element->last element
    int i = p - 1;     // i at 0 index

    for (int j = p; j < r; j++) {
        // If current element is smaller than or equal to pivot
        if (a[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(a[i], a[j]);
        }
    }
    // Place the pivot in its correct position
    swap(a[i + 1], a[r]);
    return i + 1; // Return the partition index to quicksort
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

"
Best Case : O(nlogn)
Average Case : O(nlogn)
Worst Case : O(n^2)

"
  
