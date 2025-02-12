"
 Given an array of n items
1. Compare pair of adjacent items
2.Swap if the items are out of order
3. Repeat until the end of array
  The largest item will be at the last position
4. Reduce n by 1 and go to Step 1 "
"Analogy- Large item is like “bubble” that floats to the end of the array "

void bubbleSort(int a[], int n) {
    for(int i = 0; i< n-1; i++){ // Outer loop for passes
        for(int j = 0; j < n-1-i ; j++){ // Inner loop for comparisons
            if(arr[j] > arr[j+1]){ // Compare adjacent elements
                // Swap elements
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

"
Best Case : O(n)
Average Case : O(n^2)
Worst case : O(n^2)
"
