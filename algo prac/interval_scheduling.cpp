#include <iostream>
using namespace std;

// Structure to represent an interval
struct Interval {
    int start, end, weight;
};

// Function to perform bubble sort on intervals based on their end times
void bubbleSort(Interval intervals[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (intervals[j].end > intervals[j+1].end) {
                // Swap intervals[j] and intervals[j+1]
                Interval temp = intervals[j];
                intervals[j] = intervals[j+1];
                intervals[j+1] = temp;
            }
        }
    }
}

// Function to find the last non-conflicting interval using linear search
int findLastNonConflicting(Interval intervals[], int i) {
    for (int j = i-1; j >= 0; j--) {
        if (intervals[j].end <= intervals[i].start) {
            return j;  // Return the index of the last non-conflicting interval
        }
    }
    return -1;  // No non-conflicting interval found
}

// Function to solve the weighted interval scheduling problem
int weightedIntervalScheduling(Interval intervals[], int n) {
    // Sort intervals by their end time
    bubbleSort(intervals, n);

    // Create an array to store the maximum weight for each interval
    int dp[n];
    dp[0] = intervals[0].weight;

    for (int i = 1; i < n; i++) {
        // Find the last non-conflicting interval
        int includeWeight = intervals[i].weight;
        int lastNonConflicting = findLastNonConflicting(intervals, i);
        
        // If there is a non-conflicting interval, include its weight
        if (lastNonConflicting != -1) {
            includeWeight += dp[lastNonConflicting];
        }

        // Take the maximum of including or excluding the current interval
        dp[i] = max(dp[i - 1], includeWeight);
    }

    // The answer will be in dp[n-1]
    return dp[n - 1];
}

int main() {
    int n;

    // Ask the user for the number of intervals
    cout << "Enter the number of intervals: ";
    cin >> n;

    // Arrays to store the intervals
    Interval intervals[n];

    // Take input for the intervals
    cout << "Enter the intervals (start, end, weight) for each interval:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Interval " << i+1 << ": ";
        cin >> intervals[i].start >> intervals[i].end >> intervals[i].weight;
    }

    // Find the maximum weight of non-overlapping intervals
    int result = weightedIntervalScheduling(intervals, n);

    cout << "Maximum weight of non-overlapping intervals: " << result << endl;

    return 0;
}
