#include <iostream>
#define MAX 100
#define INF 999999

using namespace std;

// E = Adjacency matrix
// COST = dummy or unused (required only to meet parameter count requirement)
// N = number of vertices
// T = starting vertex (not used in classic near[] logic but passed)

void prim(int E[][MAX], int COST[MAX], int N, int T) {
    int near[MAX];
    int MST[MAX - 1][2];
    int totalCost = 0;
    int u = -1, v = -1, min = INF;

    // Step 1: Find the minimum edge in adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (E[i][j] < min && i != j) {
                min = E[i][j];
                u = i;
                v = j;
            }
        }
    }

    MST[0][0] = u;
    MST[0][1] = v;
    totalCost += E[u][v];

    near[u] = near[v] = 0; // Mark as included

    // Step 2: Initialize near[] array
    for (int i = 0; i < N; i++) {
        if (near[i] != 0) {
            if (E[i][u] < E[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Step 3: Build MST
    for (int i = 1; i < N - 1; i++) {
        min = INF;
        int k = -1;

        for (int j = 0; j < N; j++) {
            if (near[j] != 0 && E[j][near[j]] < min) {
                min = E[j][near[j]];
                k = j;
            }
        }

        MST[i][0] = k;
        MST[i][1] = near[k];
        totalCost += E[k][near[k]];
        near[k] = 0; // Include vertex k in MST

        // Update near[] array
        for (int j = 0; j < N; j++) {
            if (near[j] != 0 && E[j][k] < E[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    // Print MST edges
    cout << "MST Edges:\n";
    for (int i = 0; i < N - 1; i++) {
        int a = MST[i][0];
        int b = MST[i][1];
        cout << a << " - " << b << " : " << E[a][b] << "\n";
    }

    cout << "Total cost of MST: " << totalCost << "\n";
}
int main() {
    const int N = 4;
    int E[MAX][MAX] = {
        {INF,  1,   4, INF},
        { 1,  INF,  2,  3},
        { 4,   2, INF,  5},
        {INF,  3,   5, INF}
    };

    int COST[MAX]; 
    int T = 0;     

    prim(E, COST, N, T);

    return 0;
}
