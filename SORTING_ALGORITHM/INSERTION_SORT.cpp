"
Similar to how most people arrange a hand of poker cards
1. Start with one card in your hand
2. Pick the next card and insert it into its proper sorted order
3.Repeat previous step for all cards"
  
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) { // Starts at index 1, as the element at index 0 is already considered "sorted."
        int next = a[i]; // Element to be inserted
        int j = i - 1;

        // j >= 0 (to ensure indices are within bounds).
        // a[j] > next (indicates that the element at a[j] is greater than the element being inserted, so it needs to be shifted).
        while (j >= 0 && a[j] > next) {
            a[j + 1] = a[j];
            j--;
        }

        // Insert `next` into the correct position
        a[j + 1] = next;
    }
}

"
Best Case : O(n)
Average Case : O(n^2)
Worst Case : O(n^2)
"
