" Sorting is the process of arranging items systematically, ordered by some criterion.
  Given an array of n items
1. Find the smallest item x, in the range of [0......n−1]
2.Swap x with the (n−1)th item
3. increase j by 1 and go to Step 1 "

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) { // Iterate up to n-2
        int minIdx = i; // Assume the first unsorted element is the smallest
        for (int j = i + 1; j < n; j++) { // Find the minimum in the remaining array
            if (a[j] < a[minIdx]) { // If we find a smaller element
                minIdx = j;
            }
        }
        // Swap the smallest element found with the first element of the unsorted part
        int temp = a[i];
        a[i] = a[minIdx];
        a[minIdx] = temp;
    }
}

" 
  Time complexity --> 
  Best case : O(n^2)
  Average case : O(n^2)
  Worst case : O(n^2)   "
