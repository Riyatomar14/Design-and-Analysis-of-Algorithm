" Sorting is the process of arranging items systematically, ordered by some criterion.
  Given an array of n items
1. Find the largest item x, in the range of [0......n−1]
2.Swap x with the (n−1)th item
3. Reduce n by 1 and go to Step 1 "

void selectionSort(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        int maxIdx = 0; // Assume the first element is the max
        for (int j = 1; j <= i; j++) { // Find the max in the range [0, i]
            if (a[j] > a[maxIdx]) {
                maxIdx = j;
            }
        }
        // Swap the elements without using a header file
        int temp = a[i];
        a[i] = a[maxIdx];
        a[maxIdx] = temp;
    }
}
