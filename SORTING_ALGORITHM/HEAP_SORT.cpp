"
1. Build a max heap from the input data
2. At this point, the largest item is stored at the root of the heap
3. Replace it with the last item of the heap followed by reducing the size of heap by 1
4. Heapify the root of the tree
5. Repeat step 3-4 while size of heap is greater than 1
"
// Function to heapify a subtree rooted at index `i`
void heapify(int a[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is larger than root
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // If right child is larger than the current largest
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // If the largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort
void heapSort(int a[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest element) to the end
        swap(a[0], a[i]);

        // Call heapify on the reduced heap
        heapify(a, i, 0);
    }
}

"
time xomplexity : O(nlogn)
"

