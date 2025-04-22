#include <iostream>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int weight[], int value[], int n) {
    // Create a 2D DP table to store the maximum value at each capacity and item index
    int dp[n+1][W+1];

    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or zero capacity
            } else if (weight[i-1] <= w) {
                // Item can be included, so we calculate the maximum of:
                // 1. Including the item: value[i-1] + dp[i-1][w - weight[i-1]]
                // 2. Excluding the item: dp[i-1][w]
                int include_item = value[i-1] + dp[i-1][w - weight[i-1]];
                int exclude_item = dp[i-1][w];
                if (include_item > exclude_item) {
                    dp[i][w] = include_item;
                } else {
                    dp[i][w] = exclude_item;
                }
            } else {
                // Item cannot be included
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // The result is in dp[n][W], which is the maximum value for the knapsack of capacity W
    return dp[n][W];
}

int main() {
    int n, W;

    // Take input for the number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int weight[n], value[n];

    // Take input for the weights and values of items
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // Call the knapsack function and output the result
    int result = knapsack(W, weight, value, n);
    cout << "The maximum value that can be obtained is: " << result << endl;

    return 0;
}
