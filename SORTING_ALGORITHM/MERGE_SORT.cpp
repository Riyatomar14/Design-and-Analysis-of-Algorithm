"
Merge Sort is a divide-and-conquer sorting algorithm
(Divide step)
1.Divide the array into two (equal) halves.
2. Recursively sort the two halves.
(Conquer step)
1.Merge the two halves to form a sorted array.
"

void merge(int a[], int low, int mid, int high) {
    int n1 = mid - low + 1; // Size of the first half
    int n2 = high - mid;    // Size of the second half

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = a[low + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = a[mid + 1 + i];
    }

    // Merge the temporary arrays back into `a[]`
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    // Copy remaining elements of `left[]` (if any)
    while (i < n1) {
        a[k++] = left[i++];
    }

    // Copy remaining elements of `right[]` (if any)
    while (j < n2) {
        a[k++] = right[j++];
    }
}

// Recursive Merge Sort function
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2; // Find the middle point

        // Recursively sort first and second halves
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        // Merge the sorted halves
        merge(a, low, mid, high);
    }
}

"
Best Case : O(nlogn)
Average Case : O(nlogn)
Best Case : O(nlogn)
" 

