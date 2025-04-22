#include <iostream>
using namespace std;

#define N 10  // Size of the array
#define BUCKETS 10

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; ++i) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // Create buckets
    float buckets[BUCKETS][N];
    int bucketSizes[BUCKETS] = {0};

    // Distribute array elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = arr[i] * BUCKETS; // Index in bucket
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }

    // Sort each bucket and concatenate
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    float arr[N] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51, 0.33, 0.18, 0.62};

    bucketSort(arr, N);

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
